#include "signal.ih"

void Signal::signal(int signum, sighandler_t handler)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;

    sigaction(signum, &sa, 0);
}