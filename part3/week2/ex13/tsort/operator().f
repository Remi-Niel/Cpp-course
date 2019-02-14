template <class RandomIt, class Compare>
inline void TSort<RandomIt, Compare>::operator()(size_t nThreads)
{
    while (true)
    {
        //Provide the amount of threads
        //The semaphore can then determine whether sorting is done
        available.wait(nThreads);

        if (nextRange.size() == 0) //When done waiting and nothing is available
        {
            available.notify_all(); //Notify others and stop
            return;
        }


        // Get next range from the queue
        qmutex.lock();
        Pair range = nextRange.front();
        nextRange.pop();
        qmutex.unlock();

        // Partition the range
        auto lhs = *range.beg;
        RandomIt mid = partition(range.beg + 1, range.end, 
            [&](auto arg)
            {
                return d_comp(arg, lhs);
            }
        );
        std::swap(*range.beg, *(mid - 1));

        // Add the resulting ranges to the queue if they contain
        // multiple elements
        if (mid - range.beg > 1)
        {
            qmutex.lock();
            nextRange.push(Pair{range.beg, mid});
            qmutex.unlock();
            available.notify_all();
        }

        if (range.end - mid > 1)
        {
            qmutex.lock();
            nextRange.push(Pair{mid, range.end});
            qmutex.unlock();
            available.notify_all();
        }
    }
}
