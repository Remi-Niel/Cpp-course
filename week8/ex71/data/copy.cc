#include "data.ih"

Data &Data::copy(Type current, Data const &other, Type next)
{
    Data copy(other, next);
    swap(current, copy, next);
    return *this;
}