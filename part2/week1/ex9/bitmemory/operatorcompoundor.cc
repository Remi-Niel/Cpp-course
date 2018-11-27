#include "bitmemory.ih"

BitMemory &BitMemory::operator|=(BitMemory const &mem)
{
    if (mem.d_nbits > d_nbits)
        enlarge(mem.d_nbits);

    size_t diff = max_bit_nr() - mem.max_bit_nr();

    for (size_t idx = 0; idx < mem.d_nbits; ++idx)
    {
        (*this)[diff + idx] |= mem[idx];
    }

    return *this;
}