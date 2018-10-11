#include "charcount.ih"

CharCount::CharCount()
{
    // start with capacity of 8, which is a pow2 so will end
    // up at 256 when muliplied by 2 often enough.
    d_charinfo.ptr = rawCapacity(8);
    d_charinfo.nChar = 0;
    d_charinfo.capacity = 8;
}