#include "bitmemory.ih"

void BitMemory::enlarge(size_t newsize)
{
    size_t oldsize = d_nbits / 8;
    size_t bytesize = (newsize + (sizeof(memory_t) - 1)) / 8;
    size_t difference = bytesize - oldsize;
    memory_t *newmem = new memory_t[bytesize];

    for (size_t idx = 0; idx < oldsize; ++idx)
        newmem[idx + difference] = d_bits[idx];

    delete[] d_bits;
    d_bits = newmem;
    d_nbits = bytesize * 8;
}