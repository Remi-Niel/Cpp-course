#include "bitset.ih"

BitSet operator<<(BitSet const &set, size_t shift)
{
    BitSet copy(set);
    copy <<= shift;
    return copy;
}