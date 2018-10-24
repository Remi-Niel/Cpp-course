#include "charcount.ih"

void CharCount::update(char newchar)
{
    for (size_t idx = 0; idx < d_charinfo.nChar; ++idx)
    {
        if(d_charinfo.ptr[idx].ch == newchar)
        {
            ++d_charinfo.ptr[idx].count;
            return;
        }
    }
}