#ifndef SIGNALCLASS_H
#define SIGNALCLASS_H

#include "signal.ih"

class Signal
{
    class Handler;

    public:
        static Signal *accessSignal();
        void signal(int signum, sighandler_t handler);
        
        // delete copy and move constructors (Singleton)
        Signal(Signal &other) = delete;
        Signal(Signal &&tmp) = delete;

        // test stuff
        void printStuff()
        {
            std::cout << "stuff\n";
        }

    private:
        Signal() = default;

};

inline Signal *Signal::accessSignal()
{
    static Signal signalInstance;
    return &signalInstance;
}

#endif