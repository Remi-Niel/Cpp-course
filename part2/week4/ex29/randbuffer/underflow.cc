#include "randbuffer.h"

int RandBuffer::underflow()
{
    int tmp = d_range * random() / (RAND_MAX + 0.1);

    return tmp % d_end;
}

