#include "bitmemory.ih"

BitMemory::BitMemory(string const &bits)
:   BitMemory()
{
    enlarge(bits.size());
    for (size_t idx = 0; idx < bits.size(); ++idx)
        set_bit(idx, bits[idx] == '1' ? 1 : 0);
}