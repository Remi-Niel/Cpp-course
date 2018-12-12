#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include "msg.h"

class Processor : private Msg
{
    // it can use Msg enums internally but other users can't
};

#endif