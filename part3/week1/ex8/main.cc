#include "main.ih"

void tsort(queue<Pair, deque<Pair, allocator<Pair>>> &nextRange, mutex &qmutex, Semaphore &available, size_t nThreads)
{
    while (true)
    {
        //provide the amount of threads
        //The semaphore can then determine if sorting is done
        available.wait(nThreads); 

        if (nextRange.size() == 0) //When done waiting and nothing is available
        {
            available.notify_all(); //Notify others and stop
            return;
        }

        // Get next range from the queue
        Pair range;
        guard(qmutex,
            [&]()
            {
                range = nextRange.front();
                nextRange.pop();
            }
        );

        // Partition the range
        int lhs = *range.beg;
        int *mid = partition(range.beg + 1, range.end, 
            [&](int arg)
            {
                return arg < lhs;
            }
        );
        swap(*range.beg, *(mid - 1));

        // Add the resulting ranges to the queue if they contain
        // multiple elements
        if (mid - range.beg > 1)
        {
            guard(qmutex,
                [&]()
                {
                    nextRange.push(Pair{range.beg, mid});
                }
            );
            available.notify_all();
        }

        if (range.end - mid > 1)
        {
            guard(qmutex,
                [&]()
                {
                    nextRange.push(Pair{mid, range.end});
                }
            );
            available.notify_all();
        }
    }

}

int main(int argc, char **argv)
{   
    if (argc < 2)
    {
        cerr << "expected size_t input\n";
        return -1;
    }

    //Generate random array of ints between [0, 1000)
    size_t size = stoi(argv[1]);
    int set[size];

    for (size_t idx = 0; idx != size; ++idx)
        set[idx] = rand() % 100000;

    queue <Pair> nextRange;
    mutex qmutex; //mutex shared by the threads

    nextRange.push(Pair{set, set + size}); // initialize the queue
    Semaphore availableRange(1);

    thread t1(tsort, ref(nextRange), ref(qmutex), ref(availableRange), 3);
    thread t2(tsort, ref(nextRange), ref(qmutex), ref(availableRange), 3);
    thread t3(tsort, ref(nextRange), ref(qmutex), ref(availableRange), 3);

    t1.join();
    t2.join();
    t3.join();

    for (int val: set)
        cout << val << ' ';
    cout << '\n';    
}
