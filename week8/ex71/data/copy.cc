#include "data.ih"

Data &Data::copy(Type current, Data const &other, Type next)
{
    destroy(current);
    (this->*s_copy[next])(other);
}