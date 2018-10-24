#include "charcount.ih"

// declare static list
void (CharCount::*CharCount::s_updater[])(char newchar) =
{   
    &CharCount::append,
    &CharCount::insert,
    &CharCount::update
};

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