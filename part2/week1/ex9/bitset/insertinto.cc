#include "bitset.ih"

#include <bitset>

void BitSet::insert_into(ostream &out) const
{
    for (size_t idx = 0; idx < d_bits.max_bit_nr(); ++idx)
    {
        if (d_bits[idx / 8] & (1 << idx % 8))
            cout << '1';
        else 
            cout << '0';
    }
}