#ifndef INCLUDED_MSG_
#define INCLUDED_MSG_

#include <cstddef>

enum class Msg
{
    NONE = 0,
    DEBUG   = 1 << 0,
    INFO    = 1 << 1,
    NOTICE  = 1 << 2,
    WARNING = 1 << 3,
    ERR     = 1 << 4,
    CRIT    = 1 << 5,
    ALERT   = 1 << 6,
    EMERG   = 1 << 7,
    ALL     = (1 << 8) - 1
};

void show(Msg value);

size_t value_of(Msg value);
Msg operator~(Msg value);
Msg operator&(Msg lvalue, Msg rvalue);
Msg operator|(Msg lvalue, Msg rvalue);
Msg operator^(Msg lvalue, Msg rvalue);

bool operator==(Msg lvalue, Msg rvalue);
bool operator!=(Msg lvalue, Msg rvalue);
bool operator!(Msg lvalue);

inline size_t value_of(Msg value)
{
    return static_cast<size_t>(value);
}

inline Msg operator~(Msg value)
{
    return static_cast<Msg>(~value_of(value));
}

inline Msg operator&(Msg lvalue, Msg rvalue)
{
    return static_cast<Msg>(value_of(lvalue) & value_of(rvalue));
}

inline Msg operator|(Msg lvalue, Msg rvalue)
{
    return static_cast<Msg>(value_of(lvalue) | value_of(rvalue));
}

inline Msg operator^(Msg lvalue, Msg rvalue)
{
    return static_cast<Msg>(value_of(lvalue) ^ value_of(rvalue));
}

inline bool operator==(Msg lvalue, Msg rvalue)
{
    return value_of(lvalue) == value_of(rvalue);
}

inline bool operator!=(Msg lvalue, Msg rvalue)
{
    return !(lvalue == rvalue);
}

inline bool operator!(Msg lvalue)
{
    return lvalue == Msg::NONE;
}

#endif
