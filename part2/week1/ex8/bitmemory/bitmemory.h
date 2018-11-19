#ifndef INCLUDED_BITMEMORY_
#define INCLUDED_BITMEMORY_

#include <cstdint>

typedef uint8_t memory_t;

class BitMemory
{

    public:

    class Proxy
    {
        memory_t &d_memory;
        size_t d_index;

        Proxy(memory_t &memory, size_t index);

        Proxy operator=(bool bit);
        Proxy operator=(Proxy const &proxy);

    };


    private:
};
        
#endif
