#include "charcount.ih"

void CharCount::append(char newchar)
{
    Char *newlist = enlarge();
    copy_until(newlist, newchar);

    //append new entry
    newlist[d_charinfo.nChar] = {newchar, 1};

    delete[] d_charinfo.ptr;
    d_charinfo.ptr = newlist;
    ++d_charinfo.nChar;
}