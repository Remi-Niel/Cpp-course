#include "bitset.ih"

void BitSet::extract_from(std::istream &in)
{   
    std::string buffer;
    while(in.good())
    {
        char c = in.peek();
        if (c != '1' && c != '0')
            break;

        buffer += c;
        in.get(); //move to next bit in buffer
    }

    d_bits = BitMemory(buffer);
}