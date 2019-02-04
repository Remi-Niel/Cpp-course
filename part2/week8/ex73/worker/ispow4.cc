#include "worker.ih"

/*
    An integer is a power of 4 when exactely 1 bit is set,
    and the number of '0' bits before the 1-bit is even.
*/

bool Worker::is_pow4(BigInt value)
{

    // Check if 1 bit is set (practically a pow2 test)
    if (value && !(value & (value - 1)))
    {
        size_t count = 0;

        while (value)
        {
            value >>= 1;
            ++count;
        }

        return count & 1;
    }

    return false;

}