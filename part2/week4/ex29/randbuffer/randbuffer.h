#ifndef INCLUDED_RANDBUFFER_
#define INCLUDED_RANDBUFFER_

#include <streambuf>

class RandBuffer: public std::streambuf
{
    int d_min;
    int d_range;
    int d_end;
    int d_buffer;

    public:
        RandBuffer(int min, int max, size_t seed);
        int underflow() override;
};
        
#endif
