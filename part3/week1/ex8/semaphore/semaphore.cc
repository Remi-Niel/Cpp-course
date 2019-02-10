#include "semaphore.ih"

Semaphore::Semaphore(size_t size)
:
    d_nAvailable(size),
    d_nWaiting(0)
{}
