#ifndef _HANDLER_H
#define _HANDLER_H

#include "msg.h"

class Handler : private Msg
{
    // it can use Msg enums internally but other users can't
};

#endif