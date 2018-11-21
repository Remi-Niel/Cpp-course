#include "bitmemory.ih"

void BitMemory::copy(memory_t *dest, memory_t *src, size_t len)
{
    size_t blocks = nblocks(len);
    for (size_t idx = 0; idx < blocks; ++idx)
        dest[idx] = src[idx];
}