#include "signalDemo.h"

SignalDemo::SignalDemo()
:
    d_pid(getpid()),
    d_loop(true)
{}

void SignalDemo::run()
{
    while (d_loop)
    {
        std::cout << 
            "Please send a SIGINT (2) or SIGTERM (15) signal to process " <<
            d_pid << '\n';

        sleep(1);
    }
}

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

// demonstration
int main()
{
    SignalDemo demo;

    Signal* instance = Signal::accessSignal();
    instance->add(SIGINT, demo);
    instance->add(SIGTERM, demo);

    demo.run();
}