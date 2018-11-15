#include "charcount.ih"

size_t CharCount::copy_until(Char* dest, char untill) const
{
    size_t idx = 0;

    for (; idx < d_charinfo.nChar; ++idx)
    {
        if(d_charinfo.ptr[idx].ch > untill)
            return idx;
        
        dest[idx] = d_charinfo.ptr[idx];
    }

    return idx;
}