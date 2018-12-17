#include "signal.ih"
#include "signalclass.h"

void Signal::signal(int signum, sighandler_t handler)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(signum, &sa, 0);
}

void Signal::add(size_t signum, Handler &object)
{
    d_sigmap.insert( std::pair<size_t, Handler &>(signum, object) );
}