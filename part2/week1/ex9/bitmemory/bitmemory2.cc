#include "bitmemory.ih"

BitMemory::BitMemory(BitMemory const &copy)
:   BitMemory()
{
    enlarge(copy.d_nbits);
    BitMemory::copy(d_bits, copy.d_bits, d_nbits / 8);
}