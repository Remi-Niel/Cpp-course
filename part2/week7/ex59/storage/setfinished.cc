#include "storage.ih"

void Storage::setFinished()
{
    lock_guard<mutex> lg(finishedMutex);
    d_finished = true;
}
