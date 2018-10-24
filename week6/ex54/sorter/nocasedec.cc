#include "sorter.ih"

int Sorter::nocasedec(string **str1, string **str2)
{
    // get length of shortest string
    size_t minLen = 
    { 
        (*str1)->length() < (*str2)->length() ?
        (*str1)->length() : (*str2)->length()
    };

    // return biggest side, of first nonmatching char.
    for (size_t ind = 0; ind != minLen; ++ind)
    {
        int result = char_compare((**str1)[ind], (**str2)[ind]);

        if (result == 0)
            continue;
        return result;
    }

    // if no difference has been found, indicate the longest string
    return (*str1)->length() > (*str2)->length() ? -1 : 1;
}