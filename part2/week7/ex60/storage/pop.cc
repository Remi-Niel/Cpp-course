#include "storage.ih"

//Signature has been changed because the client
// need to know whether the provided str has already
// been processed by another client.

bool Storage::pop(string &str)
{
    lock_guard<mutex> lg(qMutex);
    if (d_data.size() > 0 || d_data.front() == str)
    {    
        d_data.pop();
        return true;
    }

    return false;
}
