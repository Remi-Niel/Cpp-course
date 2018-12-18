#include "signal.ih"
#include "signalclass.h"
#include "handler.h"

void Signal::signal(int signum, sighandler_t handler)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(signum, &sa, 0);
}

// this function receives signums and calls the appropriate handlers 
void Signal::sigmapHandler(int signum)
{
    // getting the map inside the singleton is a hassle, is a private static 
    // data member singleton instance in Signal preferable?
    Signal *sig_ptr = Signal::accessSignal();
    std::multimap<size_t, Handler &> &map_ref = sig_ptr->d_sigmap;

    // go through all map entries associated with the signum and call their
    // objects' handle functions
    std::multimap<size_t, Handler &>::iterator iter = map_ref.find(signum);
    for ( ;iter != map_ref.end(); ++iter)
    {
        iter->second.handle(signum);
    }
}

void Signal::add(size_t signum, Handler &object)
{
    d_sigmap.insert(std::pair<size_t, Handler &>(signum, object));
    
    if (!d_sigmap.count(signum))
        signal(signum, sigmapHandler);
}

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

void Signal::ignore(size_t signum)
{
    d_sigmap.erase(signum);
    signal(signum, SIG_IGN);
}

void Signal::reset(size_t signum)
{
    d_sigmap.erase(signum);
    signal(signum, SIG_DFL);
}