#include "bitmemory.ih"

BitMemory::BitMemory(BitMemory const &copy)
:   d_nbits(copy.d_nbits), d_capacity(copy.d_capacity)
{
    enlarge(copy.d_nbits);
    BitMemory::copy(d_bits, copy.d_bits, d_nbits);
}