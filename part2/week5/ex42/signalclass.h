#ifndef SIGNALCLASS_H
#define SIGNALCLASS_H

#include "signal.ih"

class Signal
{
    class Handler;

    std::multimap<size_t, Handler> d_signal_map;

    public:
        static Signal *accessSignal();
        void signal(int signum, sighandler_t handler);

        // functions that handle Handler objects
        void add(size_t signum, Handler &object);
        void remove(size_t signum, Handler &object);
        void ignore(size_t signum);
        void reset(size_t signum);
        
        // delete copy and move constructors (Singleton)
        Signal(Signal &other) = delete;
        Signal(Signal &&tmp) = delete;

    private:
        Signal() = default;
};

inline Signal *Signal::accessSignal()
{
    static Signal signalInstance;
    return &signalInstance;
}

#endif