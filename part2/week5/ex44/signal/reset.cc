#include "signal.ih"

void Signal::reset(size_t signum)
{
    d_sigmap.erase(signum);
    signal(signum, SIG_DFL);
}