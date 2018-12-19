#ifndef INCLUDED_RANDBUFFER_
#define INCLUDED_RANDBUFFER_

#include <streambuf>

class RandBuffer: public std::streambuf
{
    int d_min;
    size_t d_range;
    int d_end;
    char *d_buffer;

    public:
        RandBuffer(int min, int max, size_t seed);
        ~RandBuffer();

        int underflow() override;
};
        
#endif
