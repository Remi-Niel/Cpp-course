#include "bitmemory.ih"

BitMemory::BitMemory(string const &bits)
:   BitMemory()
{
    enlarge(bits.size());
    cout << "reading: ";
    for (size_t idx = 0; idx < bits.size(); ++idx)
    {
        if (bits[idx] == '1')
        {
            d_bits[idx / 8] |= (1 << (idx % 8));
        }
        else
        {
            d_bits[idx / 8] &= ~(1 << (idx % 8));
        }
    }
    cout << "\n";
}