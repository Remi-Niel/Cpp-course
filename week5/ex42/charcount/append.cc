#include "charcount.ih"

void CharCount::append(char newchar)
{
    size_t newsize = d_charinfo.nChar + 1;
    Char *newlist = new Char[newsize];

    //copy data into new array
    for (size_t idx = 0; idx < d_charinfo.nChar; ++idx)
        newlist[idx] = d_charinfo.ptr[idx];

    //append new entry
    newlist[d_charinfo.nChar] = {newchar, 1};

    delete[] d_charinfo.ptr;
    d_charinfo.ptr = newlist;
    d_charinfo.nChar = newsize;
}