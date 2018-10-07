#include "charcount.ih"

void CharCount::insert(char newchar)
{
    size_t newsize = d_charinfo.nChar + 1;
    Char *newlist = new Char[newsize];

    size_t idx = 0;

    // copy characters pre newchar
    for (; idx < d_charinfo.nChar; ++idx)
    {
        if (d_charinfo.ptr[idx].ch > newchar)
            break;

        newlist[idx] = d_charinfo.ptr[idx];
    }
    
    //insert new value
    newlist[idx++] = {newchar, 1};

    //insert last characters
    for (; idx < d_charinfo.nChar; ++idx)
        newlist[idx] = d_charinfo.ptr[idx - 1];

    delete[] d_charinfo.ptr;
    d_charinfo.ptr = newlist;
    d_charinfo.nChar = newsize;
}