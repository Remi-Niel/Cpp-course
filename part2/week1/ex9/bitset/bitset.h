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
        BitSet(BitSet const &copy);

        size_t size() const;

        BitSet &operator<<=(size_t shift);
        friend BitSet operator<<(BitSet const &set, size_t shift);
        
        BitSet &operator|=(BitSet const &rvalue);
        friend BitSet operator|(BitSet const &left, BitSet const &right);

        BitSet &operator&=(BitSet const &rvalue);
        friend BitSet operator&(BitSet const &left, BitSet const &right);

        BitMemory::Proxy operator[](size_t idx);
        BitMemory::Proxy operator[](size_t idx) const;

        friend std::istream &operator>>(std::istream &in, BitSet &set);
        friend std::ostream &operator<<(std::ostream &os, BitSet const &set);

    private:
        void insert_into(std::ostream &out) const;
        void extract_from(std::istream &in);
};

inline BitSet::BitSet(size_t n_bits)
:   d_bits(n_bits)
{ }

inline BitSet::BitSet(std::string const &bits)
:   d_bits(bits)
{ }

inline BitSet::BitSet(BitSet const &copy)
:   d_bits(copy.d_bits)
{ }

inline size_t BitSet::size() const
{
    return d_bits.max_bit_nr();
}

inline BitSet &BitSet::operator<<=(size_t shift)
{
    d_bits <<= shift;
    return *this;
}

inline BitSet &BitSet::operator|=(BitSet const &set)
{
    d_bits |= set.d_bits;
    return *this;
}

inline BitSet &BitSet::operator&=(BitSet const &set)
{
    d_bits &= set.d_bits;
    return *this;
}
        
inline BitMemory::Proxy BitSet::operator[](size_t idx)
{
    return d_bits[idx];
}

inline BitMemory::Proxy BitSet::operator[](size_t idx) const
{
    return d_bits[idx];
}

inline std::ostream &operator<<(std::ostream &out, BitSet const &set)
{
    set.insert_into(out);
    return out;
}

inline std::istream &operator>>(std::istream &in, BitSet &set)
{
    set.extract_from(in);
    return in;
}

#endif
