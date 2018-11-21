#include "bitmemory.ih"

BitMemory::Proxy BitMemory::proxy(size_t idx) const
{
    return BitMemory::Proxy(
        d_bits[idx / (sizeof(memory_t) * 8)],
        idx % (sizeof(memory_t) * 8)
    );
}