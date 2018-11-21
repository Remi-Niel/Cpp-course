#include "bitmemory.ih"

BitMemory &BitMemory::operator|=(BitMemory const &mem)
{
    if (mem.d_nbits > d_nbits)
        enlarge(d_nbits + mem.d_nbits);

    size_t difference = d_nbits - mem.d_nbits;

    for (size_t idx = difference; idx < (d_nbits / blocksize()); ++idx)
        d_bits[idx] |= mem.d_bits[idx - difference];

    return *this;
}