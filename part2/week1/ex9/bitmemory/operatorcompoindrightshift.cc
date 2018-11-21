#include "bitmemory.ih"

BitMemory &BitMemory::operator<<=(size_t shift)
{
    enlarge(d_nbits + shift);

    size_t memshift = shift / sizeof(memory_t);
    size_t bitshift = shift % sizeof(memory_t);

    // shift for complete memory blocks.
    // if (memshift)
    //     memory_shift(memshift);

    size_t end = (d_nbits / 8) - 1;
    for (size_t idx = 0; idx != end; ++idx)
    {
        d_bits[idx] |= d_bits[idx + 1] >> (sizeof(memory_t) - bitshift);
        d_bits[idx + 1] <<= bitshift;
    }

    return *this;
}