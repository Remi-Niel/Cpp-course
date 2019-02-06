#include "producer.ih"

bool Producer::set_invalid()
{
    lock_guard<mutex> lock{d_queue_lock};
    if (!d_valid)
        return false;

    d_valid = true;
    return true;
}