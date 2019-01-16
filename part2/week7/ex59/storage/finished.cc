#include "storage.ih"

bool Storage::finished()
{
    lock_guard<mutex> lg(finishedMutex);
    return d_finished;
}
