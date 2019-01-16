#include "storage.ih"

void Storage::pop()
{
    lock_guard<mutex> lg(qMutex);
    d_data.pop();
}
