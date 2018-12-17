#ifndef HANDLER_H
#define HANDLER_H

#include "signal.ih"
#include "signalclass.h"

class Signal::Handler
{
    friend class Signal;

    public:
        virtual ~Handler();

    private:
        virtual void handle(size_t signum) = 0;
};

#endif