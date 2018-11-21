#include "bitmemory.ih"

BitMemory::Proxy BitMemory::operator[](size_t idx)
{
    return proxy(idx);
}