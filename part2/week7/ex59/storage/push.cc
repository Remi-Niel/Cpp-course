#include "storage.ih"

void Storage::push(string &str)
{
    lock_guard<mutex> lg(qMutex);
    d_data.push(str);
}
