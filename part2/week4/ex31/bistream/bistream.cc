#include "bistream.ih"

BiStream::BiStream(ostream &one, ostream &two)
:
    BiStreamBuffer(one, two),
    ostream(this)
{
    setp(0, 0);
}
