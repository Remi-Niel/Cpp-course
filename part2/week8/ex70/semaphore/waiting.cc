#include "semaphore.ih"

size_t Semaphore::waiting() const
{
    return d_nWaiting;
}