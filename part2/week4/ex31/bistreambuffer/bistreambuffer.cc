#include "bistreambuffer.ih"

BiStreamBuffer::BiStreamBuffer(ostream &one, ostream &two)
:
    streambuf(),
    d_one(one),
    d_two(two)
{
}
