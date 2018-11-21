#include "bitset.ih"

BitSet operator|(BitSet const &left, BitSet const &right)
{
    BitSet copy(left);
    copy |= right;
    return copy;
}