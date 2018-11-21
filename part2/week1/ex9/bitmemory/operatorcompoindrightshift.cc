#include "bitmemory.ih"

BitMemory &BitMemory::operator<<=(size_t shift)
{
    enlarge(d_nbits + shift);

    size_t end = nblocks(d_nbits);
    for (size_t idx = 1; idx != end; ++idx)
    {
        d_bits[idx - 1] = (d_bits[idx - 1] >> shift)
                        | (d_bits[idx] << (8 - shift));
    }
    d_bits[end - 1] = d_bits[end - 1] >> shift;
    return *this;
}