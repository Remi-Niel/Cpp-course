#include "bitmemory.ih"

BitMemory &BitMemory::operator=(BitMemory const &copy)
{
    BitMemory tmp{ copy };
    swap(tmp);
    return *this;
}