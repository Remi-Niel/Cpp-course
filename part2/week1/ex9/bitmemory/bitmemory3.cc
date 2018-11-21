#include "bitmemory.ih"

BitMemory::BitMemory(BitMemory &&move)
:   d_nbits(move.d_nbits),
    d_capacity(move.d_capacity),
    d_bits(move.d_bits)
{
    move.d_nbits = 0;
    move.d_capacity = 0;
    move.d_bits = nullptr;
}