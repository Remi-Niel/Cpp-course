#include "semaphore.h"

Semaphore::Semaphore(size_t size)
:
    d_nAvailable(size)
{}

// notifies a single waiting thread when storage is available
void Semaphore::notify()    
{
    std::lock_guard<std::mutex> lk(d_mutex);
    if (d_nAvailable++ == 0)
        d_condition.notify_one();
}

// notifies all waiting threads when storage is available
void Semaphore::notify_all()
{
    std::lock_guard<std::mutex> lk(d_mutex);
    if (d_nAvailable++ == 0)
        d_condition.notify_all();
}

inline size_t Semaphore::size() const
{
    return d_nAvailable;
}

void Semaphore::wait()
{
    std::unique_lock<std::mutex> lk(d_mutex);
    while (d_nAvailable == 0)
        d_condition.wait(lk);   // releases lock and waits for available item
    
    --d_nAvailable;            
}
