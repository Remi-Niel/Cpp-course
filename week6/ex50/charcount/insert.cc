#include "charcount.ih"

void CharCount::insert(char newchar)
{
    size_t newsize = d_charinfo.nChar + 1;
    if (newsize > d_charinfo.capacity)
        enlarge();

    size_t idx = d_charinfo.nChar;
    for (; idx--;)
    {
        if (d_charinfo.ptr[idx].ch < newchar)
            break;

        d_charinfo.ptr[idx + 1] = d_charinfo.ptr[idx];
    }

    d_charinfo.ptr[idx + 1] = { newchar, 1 };
}