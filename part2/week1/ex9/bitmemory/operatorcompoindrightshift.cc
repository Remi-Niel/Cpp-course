#include "bitmemory.ih"

BitMemory &BitMemory::operator<<=(size_t shift)
{
    enlarge(d_nbits + shift);

    size_t end = (d_nbits / 8) - 1;
    for (size_t idx = 1; idx != end; ++idx)
    {
        d_bits[idx - 1] |= d_bits[idx] >> (sizeof(memory_t) - shift);
        d_bits[idx] <<= shift;
    }

    return *this;
}