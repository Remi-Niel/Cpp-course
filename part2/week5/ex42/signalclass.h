#ifndef SIGNALCLASS_H
#define SIGNALCLASS_H

#include <csignal>
#include <map>

class Signal
{
    public:
        class Handler;

    std::multimap<size_t, Handler &> d_sigmap;

    public:
        static Signal &accessSignal();
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
        Signal();
};

// nested class that can be inherited from to handle signals in objects
class Signal::Handler
{
    friend class Signal;

    public:
        virtual ~Handler();

    private:
        virtual void handle(size_t signum) = 0;
};

#endif