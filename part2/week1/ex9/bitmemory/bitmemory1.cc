#include "bitmemory.ih"

BitMemory::BitMemory(string const &bits)
:   BitMemory()
{
    enlarge(bits.size());
    for (size_t idx = 0; idx < bits.size(); ++idx)
    {
        if (bits[idx] == '1')
            (*this)[idx] = 1;
        else
            (*this)[idx] = 0;
    }
}