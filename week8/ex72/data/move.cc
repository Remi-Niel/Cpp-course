#include "data.ih"

Data &Data::move(Type current, Data &&other, Type next)
{
    swap(current, other, next);
    return *this;
}