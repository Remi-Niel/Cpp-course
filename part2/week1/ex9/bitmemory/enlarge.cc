#include "bitmemory.ih"

void BitMemory::enlarge(size_t newsize)
{
    size_t blocksize = sizeof(memory_t);
    size_t oldsize = d_nbits / sizeof(memory_t);
    size_t bytesize = (newsize + blocksize - 1) / sizeof(memory_t);
    size_t difference = bytesize - oldsize;
    
    memory_t *newmem = new memory_t[bytesize];
    
    for (size_t idx = 0; idx < oldsize; ++idx)
        newmem[idx + difference] = d_bits[idx];

    if (d_bits)
        delete[] d_bits;
    d_bits = newmem;
    d_nbits = bytesize * blocksize;
}