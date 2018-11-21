#include "bitset.ih"

void BitSet::extract_from(std::istream &in)
{   
    size_t read = 0;
    while(in.good())
    {
        char c = in.peek();
        if (c != '1' && c != '0')
            break;

        if (read >= d_bits.max_bit_nr())
            d_bits.enlarge(d_bits.max_bit_nr() + 8);
            
        d_bits[d_bits.max_bit_nr() - read++] = (c == '1' ? 1 : 0);
        in.get(); //move to next bit in buffer
    }
}