#include "signal.ih"

void Signal::add(size_t signum, Handler &object)
{
    d_sigmap.insert(std::pair<size_t, Handler &>(signum, object));

    if (d_sigmap.count(signum) == 1)
        signal(signum, sigmapHandler);
}