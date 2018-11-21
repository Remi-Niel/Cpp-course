#include "bitmemory.ih"

BitMemory::Proxy BitMemory::proxy(size_t idx) const
{
    return BitMemory::Proxy(
        d_bits[idx / blocksize()],
        idx % blocksize()
    );
}