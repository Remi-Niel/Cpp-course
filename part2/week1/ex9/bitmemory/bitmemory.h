#ifndef INCLUDED_BITMEMORY_
#define INCLUDED_BITMEMORY_

#include <string>
#include <cstring>
#include <cstddef>
#include <cstdint>

typedef uint8_t memory_t;

class BitMemory
{
    size_t d_nbits;
    memory_t *d_bits;

    public:
        class Proxy;

        BitMemory();
        BitMemory(size_t bits);
        BitMemory(std::string const &bits);
        BitMemory(BitMemory const &copy);
        BitMemory(BitMemory &&move);
        ~BitMemory();

        size_t max_bit_nr() const;

        void swap(BitMemory &swap);
        BitMemory &operator=(BitMemory const &copy);
        BitMemory &operator=(BitMemory &&move);
    
        BitMemory &operator<<=(size_t shift);
        BitMemory::Proxy operator[](size_t idx);
        BitMemory::Proxy operator[](size_t idx) const;

    private:
        static void copy(memory_t *dest, memory_t *src, size_t bits);

        BitMemory::Proxy proxy(size_t idx) const;
        void enlarge(size_t newsize); //newsize in bits.

};

inline BitMemory::BitMemory()
:   d_nbits(0), d_bits(nullptr)
{ }

inline BitMemory::BitMemory(size_t bits)
:   BitMemory()
{
    enlarge(bits);
}

inline size_t BitMemory::max_bit_nr() const
{
    return d_nbits;
}

inline BitMemory::Proxy BitMemory::operator[](size_t idx)
{
    return proxy(idx);
}

inline BitMemory::Proxy BitMemory::operator[](size_t idx) const
{
    return proxy(idx);
}

inline BitMemory::Proxy BitMemory::proxy(size_t idx) const
{
    return BitMemory::Proxy(d_bits[idx / 8], idx % 8);
}

#endif
