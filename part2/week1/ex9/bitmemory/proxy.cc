#include "bitmemory.ih"

BitMemory::Proxy BitMemory::proxy(size_t idx) const
{
    idx += capacity() - max_bit_nr();
    return BitMemory::Proxy(
        d_bits[idx / blocksize()],
        idx % blocksize()
    );
}