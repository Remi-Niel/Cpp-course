#include "charcount.ih"

void CharCount::enlarge()
{
    size_t newcap = d_charinfo.capacity * 2;
    Char* newlist = rawCapacity(newcap);

    for (size_t idx = 0; idx < d_charinfo.nChar; ++idx)
        newlist[idx] = d_charinfo.ptr[idx];

    operator delete(d_charinfo.ptr);
    d_charinfo.ptr = newlist;
    d_charinfo.capacity = newcap;
}