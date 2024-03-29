#include "bitmemory.ih"

BitMemory::BitMemory(string const &bits)
:   BitMemory()
{
    enlarge(bits.size());
    size_t pad = 0;

    for (size_t idx = 0; idx < bits.size(); ++idx)
    {
        if (bits[idx] == '1')
            (*this)[idx + pad] = 1;
        else
            (*this)[idx + pad] = 0;
    }
}