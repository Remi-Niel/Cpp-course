#include "bistream.ih"

BiStream::BiStream(ofstream &one, ofstream &two)
:
    BiStreamBuffer(one.rdbuf(), two.rdbuf()),
    ostream(this)
{
}
