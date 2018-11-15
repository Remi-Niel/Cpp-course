#include "charcount.ih"

CharCount::~CharCount()
{
    operator delete(d_charinfo.ptr);
}