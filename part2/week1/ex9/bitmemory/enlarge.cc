#include "bitmemory.ih"

void BitMemory::enlarge(size_t newsize)
{
    size_t blocksize = sizeof(memory_t) * 8;
    size_t oldsize = d_nbits / blocksize;
    size_t bytesize = (newsize + blocksize - 1) / blocksize;
    size_t difference = bytesize - oldsize;
    
    memory_t *newmem = new memory_t[bytesize];
    for (size_t idx = 0; idx < difference; ++idx)
        newmem[idx] = 0;

    for (size_t idx = 0; idx < oldsize; ++idx)
        newmem[idx + difference] = d_bits[idx];

    if (d_bits)
        delete[] d_bits;
    d_bits = newmem;
    d_nbits = bytesize * blocksize;
}