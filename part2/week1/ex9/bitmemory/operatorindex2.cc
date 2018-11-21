#include "bitmemory.ih"

BitMemory::Proxy BitMemory::operator[](size_t idx) const
{
    return proxy(idx);
}