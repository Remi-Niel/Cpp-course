#include "charcount.ih"

void CharCount::append(char newchar)
{
    size_t newsize = d_charinfo.nChar + 1;
    if(newsize > d_charinfo.capacity)
        enlarge();
    
    //append new entry
    d_charinfo.ptr[d_charinfo.nChar] = { newchar, 1 };
    d_charinfo.nChar = newsize;
}