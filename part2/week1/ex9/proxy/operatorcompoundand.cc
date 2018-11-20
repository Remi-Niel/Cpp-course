#include "proxy.ih"

BitMemory::Proxy &BitMemory::Proxy::operator&=(size_t bit)
{
    if (static_cast<size_t>(*this) && bit)
        *this = 1;
    else
        *this = 0;
    
    return *this;
}