#include "charcount.ih"

Char *CharCount::rawCapacity(size_t size)
{
    return static_cast<Char*>(operator new(size * sizeof(Char)));
}