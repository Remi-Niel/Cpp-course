#include "worker.ih"

#include <iostream> //_DBG

Result Worker::collatz(BigInt value)
{
    Result result{value};

    while (!(value == 1)) // value != 1 doesn't work for some reason.
    {
        result.d_highest = max(result.d_highest, value);
        ++result.d_length;
        
        if ((value & 1) == 0)
        {
            value >>= 1;
            if (is_pow4(value))
                ++result.d_pow4_count;
        }
        else
            value += (value << 1) + 1;

    }

    return result;
}