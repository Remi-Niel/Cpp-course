#ifndef INCLUDED_TSORT_
#define INCLUDED_TSORT_

#include "../semaphore/semaphore.h"
#include <queue>
#include <mutex>

template <class RandomIt, class Compare>
class TSort
{   

    struct Pair
    {
        RandomIt beg;
        RandomIt end;
        Pair() = default;
        Pair(RandomIt b, RandomIt e)
        :
            beg(b),
            end(e)
        {}
    };

    Semaphore available;
    std::queue<Pair> nextRange;
    Compare d_comp;

    mutable std::mutex qmutex;

    size_t n_Done;

    public:
        TSort(RandomIt beg, RandomIt end, Compare pred);
        void operator()(size_t nThreads);
        void setFinished(bool finished);

};


#include "tsort.f"

#include "operator().f"

#endif    