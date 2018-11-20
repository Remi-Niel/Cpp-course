#include "proxy.ih"

BitMemory::Proxy &BitMemory::Proxy::operator=(size_t bit)
{
    if (bit)
        d_memory |= (1 << d_index);
    else 
        d_memory &= ~(1 << d_index);

    return *this;
}