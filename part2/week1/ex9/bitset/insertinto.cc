#include "bitset.ih"

#include <bitset>

void BitSet::insert_into(ostream &out) const
{
    size_t idx = 0;
    for (; idx < d_bits.max_bit_nr(); ++idx)
    {
        if (static_cast<size_t>(d_bits[idx]))
            cout << '1';
        else 
            cout << '0';
    }
}