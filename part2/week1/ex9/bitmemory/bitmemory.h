#ifndef INCLUDED_BITMEMORY_
#define INCLUDED_BITMEMORY_

#include <cstddef>
#include <cstdint>

typedef uint8_t memory_t;

class BitMemory
{
    size_t d_nbits;
    size_t d_capacity; // in bits.
    memory_t *d_bits;

    public:
        class Proxy;

        BitMemory();
        BitMemory(size_t n_bits);
        BitMemory(std::string const &bits);
        BitMemory(BitMemory const &copy);
        BitMemory(BitMemory &&move);

        size_t max_bit_nr() const;

        void swap(BitMemory &swap);
        BitMemory &operator=(BitMemory const &copy);
        BitMemory &operator=(BitMemory &&move);
    
        BitMemory &operator<<=(size_t shift);
        BitMemory::Proxy operator[](size_t idx);
        BitMemory::Proxy operator[](size_t idx) const;

    private:
        Proxy proxy(size_t idx);
        void enlarge(size_t newsize); //newsize in bits.

};
        
#endif
