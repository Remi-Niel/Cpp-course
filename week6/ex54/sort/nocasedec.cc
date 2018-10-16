#include "sort.ih"

int Sort::nocasedec(string **str1, string **str2)
{
        // get length of shortest string
    size_t minLen = 
    { 
        (*str1)->length() < (*str2)->length() ?
        (*str1)->length() : (*str2)->length()
    };

        // check whether strings differ at any ascii character
        // if so, indicate the string with the 'later' character
    for (size_t ind = 0; ind != minLen; ++ind)
    {
        char chr1 = tolower((**str1)[ind]);
        char chr2 = tolower((**str2)[ind]);

        if (chr1 > chr2)
            return -1;

        if (chr2 > chr1)
            return 1;
    }

        // if no difference has been found, indicate the longest string
    return (*str1)->length() > (*str2)->length() ? -1 : 1;
}