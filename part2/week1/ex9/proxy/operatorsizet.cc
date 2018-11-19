#include "proxy.ih"

BitMemory::Proxy::operator size_t() const
{
    if (d_memory & (1 << d_index)) return 1;
    return 0;
}
