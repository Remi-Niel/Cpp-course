#include "bistreambuffer.ih"

BiStreamBuffer::BiStreamBuffer(streambuf *one, streambuf *two)
:
    streambuf(),
    d_one(one),
    d_two(two)
{
}
