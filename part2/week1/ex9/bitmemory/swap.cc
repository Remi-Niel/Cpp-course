#include "bitmemory.ih"

void BitMemory::swap(BitMemory &swap)
{
    char buf[sizeof(BitMemory)];
    memcpy(buf, this, sizeof(BitMemory));
    memcpy(reinterpret_cast<char *>(this), &swap, sizeof(BitMemory));
    memcpy(reinterpret_cast<char *>(&swap), buf, sizeof(BitMemory));
}