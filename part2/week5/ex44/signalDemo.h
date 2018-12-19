#ifndef SIGNALDEMO_H
#define SIGNALDEMO_H

#include "signal.ih"

#include <sys/types.h>
#include <unistd.h>

class SignalDemo : public Signal::Handler
{
    pid_t d_pid;
    volatile bool d_loop;

    public:
        SignalDemo();
        void run();

    private:
        void handle(size_t signum) override;
};

#endif