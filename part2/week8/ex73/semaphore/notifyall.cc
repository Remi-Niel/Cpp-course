#include "semaphore.ih"

void Semaphore::notify_all()
{
    std::lock_guard<mutex> lock(d_mutex);
    ++d_count;
    d_condition.notify_all();
}