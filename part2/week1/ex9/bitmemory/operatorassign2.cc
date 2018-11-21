#include "bitmemory.ih"

BitMemory &BitMemory::operator=(BitMemory &&move)
{
    swap(move);
    return *this;
}