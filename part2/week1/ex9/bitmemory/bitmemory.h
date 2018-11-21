#ifndef INCLUDED_BITMEMORY_
#define INCLUDED_BITMEMORY_

#include <string>
#include <cstring>
#include <cstddef>
#include <cstdint>

typedef uint8_t memory_t;

class BitMemory
{
    size_t d_nbits; // bits in use.
    size_t d_capacity; // total blocks of capacity.
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
        size_t capacity() const;

        void swap(BitMemory &swap);
        BitMemory &operator=(BitMemory const &copy);
        BitMemory &operator=(BitMemory &&move);

        BitMemory &operator|=(BitMemory const &mem);
        BitMemory &operator&=(BitMemory const &mem);
    
        BitMemory &operator<<=(size_t shift);
        BitMemory::Proxy operator[](size_t idx);
        BitMemory::Proxy operator[](size_t idx) const;

        void enlarge(size_t newsize); //newsize in bits.
    private:
        static size_t blocksize();
        static size_t nblocks(size_t nbits);
        static void copy(memory_t *dest, memory_t *src, size_t bits);

        // void set_bit(size_t idx, size_t val);
        BitMemory::Proxy proxy(size_t idx) const;

};

inline BitMemory::BitMemory()
:   d_nbits(0), d_capacity(0), d_bits(nullptr)
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

inline size_t BitMemory::capacity() const
{
    return d_capacity;
}

inline size_t BitMemory::blocksize()
{
    return sizeof(memory_t) * 8;
}

inline size_t BitMemory::nblocks(size_t nbits)
{
    return (nbits + (blocksize() - 1)) / blocksize();
}

#endif
