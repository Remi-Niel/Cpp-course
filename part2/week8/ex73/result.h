#ifndef __RESULT_HPP
#define __RESULT_HPP

#include <boost/multiprecision/cpp_int.hpp>

typedef boost::multiprecision::cpp_int BigInt;

struct Result
{
    BigInt d_value;
    BigInt d_highest;
    size_t d_pow4_count;
    size_t d_length;

    Result(BigInt const &value);
};

inline Result::Result(BigInt const &value)
:
    d_value(value),
    d_highest(0),
    d_pow4_count(0),
    d_length(0)
{ }

#endif