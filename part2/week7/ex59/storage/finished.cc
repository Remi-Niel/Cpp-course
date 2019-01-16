#include "storage.ih"

bool Storage::finished()
{
    finishedMutex.lock();
    bool done = d_finished;
    finishedMutex.unlock();

    return done;
}
