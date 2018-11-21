#include "bitmemory.ih"

void BitMemory::enlarge(size_t size)
{
    size_t oldsize = nblocks(d_nbits);
    size_t newsize = nblocks(size);
    size_t block_diff = newsize - oldsize;
    
    memory_t *newmem = new memory_t[newsize];
    for (size_t idx = 0; idx < block_diff; ++idx)
        newmem[idx] = 0;

    for (size_t idx = 0; idx < oldsize; ++idx)
        newmem[idx + block_diff] = d_bits[idx];

    if (d_bits)
        delete[] d_bits;
    d_bits = newmem;
    d_nbits = size;
    d_capacity = newsize * blocksize();
}