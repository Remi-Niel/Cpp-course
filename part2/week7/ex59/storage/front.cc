#include "storage.ih"

string Storage::front()
{
    lock_guard<mutex> lg(qMutex);
    return *d_data.front();
}
