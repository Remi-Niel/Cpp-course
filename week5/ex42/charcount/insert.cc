#include "charcount.ih"

void CharCount::insert(char newchar)
{
    Char *newlist = enlarge();
    size_t idx = copy_until(newlist, newchar);
    
    //insert new value
    newlist[idx++] = {newchar, 1};

    //insert last characters
    for (size_t newsize = d_charinfo.nChar + 1; idx < newsize; ++idx)
    {
        newlist[idx] = d_charinfo.ptr[idx - 1];
    }

    delete[] d_charinfo.ptr;
    d_charinfo.ptr = newlist;
    ++d_charinfo.nChar;
}