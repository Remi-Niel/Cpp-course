#include "bitmemory.ih"

BitMemory &BitMemory::operator|=(BitMemory const &mem)
{
    if (mem.d_nbits > d_nbits)
        enlarge(mem.d_nbits);

    for (size_t idx = 0; idx < mem.d_nbits; ++idx)
    {
        (*this)[max_bit_nr() - 1 - idx] |= mem[mem.max_bit_nr() - 1 - idx];
    }

    return *this;
}