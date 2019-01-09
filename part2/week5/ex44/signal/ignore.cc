#include "signal.ih"

void Signal::ignore(size_t signum)
{
    d_sigmap.erase(signum);
    signal(signum, SIG_IGN);
}