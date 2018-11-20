#ifndef INCLUDED_BITSET_
#define INCLUDED_BITSET_

#include <string>
#include <iostream>

#include "../proxy/proxy.h"
#include "../bitmemory/bitmemory.h"

// Literal operator
std::string operator "" _bits(char const *literal);

class BitSet
{
    BitMemory d_bits;

    public:
        BitSet(size_t n_bits = 8);
        BitSet(std::string const &bits);

        size_t size();

        BitSet &operator<<=(size_t shift);
        friend BitSet operator<<(BitSet const &set, size_t shift);
        
        BitSet &operator|=(BitSet const &rvalue);
        friend BitSet operator|(BitSet const &lvalue, BitSet const &rvalue);

        BitSet &operator&=(BitSet const &rvalue);

        BitMemory::Proxy operator[](size_t idx);
        BitMemory::Proxy operator[](size_t idx) const;

        friend std::istream &operator>>(std::istream &in, BitSet const &set);
        friend std::ostream &operator<<(std::ostream &os, BitSet const &set);

    private:
        void insert_into(std::ostream &out) const;
        void extract_from(std::istream &in) const;
};
        
#endif
