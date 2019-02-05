#include "semaphore.ih"

void Semaphore::wait(size_t nThreads)
{
    std::unique_lock<std::mutex> lk(d_mutex);
    while (d_nAvailable == 0)
    {
        incrementWaiting();     // save increment
        if(d_nWaiting == nThreads - 1) // If everyone is waiting work is done
            return;
        d_condition.wait(lk);   // releases lock and waits for available item
        decrementWaiting();     // save decrement
    }

    --d_nAvailable;            
}