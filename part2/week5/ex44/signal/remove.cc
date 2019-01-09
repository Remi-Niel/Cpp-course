#include "signal.ih"

void Signal::remove(size_t signum, Handler &object)
{
    std::multimap<size_t, Handler &>::iterator iter = d_sigmap.find(signum);
    
    for ( ;iter != d_sigmap.end(); ++iter)
    {
        if (std::addressof(iter->second) == std::addressof(object))
            d_sigmap.erase(iter);
    }

    if (!d_sigmap.count(signum))
        signal(signum, SIG_DFL);
}