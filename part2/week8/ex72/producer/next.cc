#include "producer.ih"

string Producer::next()
{
    lock_guard<mutex> lock{d_queue_lock};

    if (!d_valid || d_sourcefiles.empty())
        return "";

    string rval = d_sourcefiles.front();
    d_sourcefiles.pop();
    return rval;
}