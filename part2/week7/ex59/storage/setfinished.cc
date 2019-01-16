#include "storage.ih"

void Storage::setFinished()
{
    finishedMutex.lock();
    d_finished = true;
    finishedMutex.unlock();
}
