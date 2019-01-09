#include "signaldemo.ih"

void SignalDemo::handle(size_t signum)
{
    if (signum == SIGINT)
        std::cout << "Received SIGINT (2), continuing loop...\n";
    else if (signum == SIGTERM)
    {
        std::cout << "Received SIGTERM (15), stopping loop.\n";
        d_loop = false;
    }
}