#ifndef SIGNALCLASS_H
#define SIGNALCLASS_H

#include "signal.ih"

class Signal
{
    class Handler;

    std::multimap<size_t, Handler &> d_sigmap;

    public:
        static Signal *accessSignal();
        void signal(int signum, sighandler_t handler);
        static void sigmapHandler(int signum);

        // functions that handle Handler objects
        void add(size_t signum, Handler &object);
        void remove(size_t signum, Handler &object);
        void ignore(size_t signum);
        void reset(size_t signum);
        
        // delete copy and move constructors (Singleton)
        Signal(Signal const &other) = delete;
        Signal(Signal &&tmp) = delete;

    private:
        Signal() = default;

        // prevent assignment by hiding the functions (Singleton)
        Signal &operator=(Signal const &other);
        Signal &operator=(Signal &&tmp);
};

// construct singleton in static variable on first call, after that
// simply return pointer to existing singleton
inline Signal *Signal::accessSignal()
{
    static Signal signalInstance;
    return &signalInstance;
}

#endif