#include "bitmemory.ih"

BitMemory::~BitMemory()
{
    if (d_bits)
        delete[] d_bits;
}