#include "bitmemory.ih"

void BitMemory::copy(memory_t *dest, memory_t *src, size_t len)
{
    for (size_t idx = 0; idx < len; ++idx)
        dest[idx] = src[idx];
}