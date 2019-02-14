#include "main.ih"

template <class RandomIt, class Compare>
void tsort(RandomIt beg, RandomIt end, Compare pred)
{
    vector<thread> threads{};
    size_t nThreads = 3;
    
    TSort<RandomIt, Compare> tsort(beg, end, pred);

    thread t1(ref(tsort), nThreads);
    thread t2(ref(tsort), nThreads);
    thread t3(ref(tsort), nThreads);

    t1.join();
    t2.join();
    t3.join();
}


int main()
{
    // define some sortable data structure, e.g., a vector:
    vector<int> data{6,3,45,7,4,6,34,65,23,65};

                                            // tsort has the same
                                            // signatures as STL's sort
                                          // algorithm
    tsort(data.begin(), data.end(), less<int>{});

    for (int val: data)
        cout << val << ' ';
    cout << '\n';   

    // display data's value using any available method
}
