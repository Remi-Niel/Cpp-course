#ifndef INCLUDED_MESSAGE_H_
#define INCLUDED_MESSAGE_H_

#include "../base/base.h"

class Message
{
    Base *d_base;

    public:
        Message(Base &base);
        void show(std::ostream &out);
};

Message::Message(Base &base)
:
    d_base(&base)
{}

void Message::show(std::ostream &out)
{
    d_base->hello(out);
}

#endif