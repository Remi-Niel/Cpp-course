#include "main.ih"

// demonstration
int main()
{
    SignalDemo demo;

    Signal &instance = Signal::accessSignal();
    instance.add(SIGINT, demo);
    instance.add(SIGTERM, demo);

    demo.run();
}