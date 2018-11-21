#include "bitset.ih"

#include <bitset>

void BitSet::insert_into(ostream &out) const
{
    size_t idx = (d_bits.capacity() - d_bits.max_bit_nr());
    for (idx; idx < d_bits.capacity(); ++idx)
    {
        if (static_cast<size_t>(d_bits[idx]))
            cout << '1';
        else 
            cout << '0';
    }
}