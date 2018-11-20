#ifndef INCLUDED_PROXY_
#define INCLUDED_PROXY_

#include <cstddef>
#include "../bitmemory/bitmemory.h"

class BitMemory::Proxy
{
    memory_t &d_memory;
    size_t d_index;
    
    public:    
        operator size_t() const;
        Proxy &operator=(size_t bit);
        Proxy &operator=(Proxy const &proxy);

        Proxy &operator&=(size_t bit);
        Proxy &operator|=(size_t bit);

    private:
        friend class BitMemory;
        Proxy(memory_t &memory, size_t index);
};

inline BitMemory::Proxy::Proxy(memory_t &mem, size_t idx)
:   d_memory(mem), d_index(idx)
{ }

inline BitMemory::Proxy &BitMemory::Proxy::operator=(Proxy const &proxy)
{
    return (*this = static_cast<size_t>(proxy));
}

#endif
