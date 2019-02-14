template <class RandomIt, class Compare>
TSort<RandomIt, Compare>::TSort(RandomIt beg, RandomIt end, Compare pred)
:
    available{},
    qmutex{}
{      
    nextRange.push(Pair{beg, end});
    available.notify_all();
    d_comp = pred;
}