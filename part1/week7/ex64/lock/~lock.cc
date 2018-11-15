#include "lock.ih"

Lock::~Lock()
{
    if (valid())
        close(d_file);
}