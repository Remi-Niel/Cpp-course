#include "semaphore.ih"

void Semaphore::notify()
{
    lock_guard<mutex> lock(d_mutex);
    ++d_count;
    d_condition.notify_one();
}