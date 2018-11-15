#include "sorter.ih"

// indicates the latter character,
// or 0 on equal.
int Sorter::char_compare(char c1, char c2)
{
    c1 = tolower(c1);
    c2 = tolower(c2);
    
    if (c1 == c2)
        return 0;

    return (c1 > c2 ? -1 : 1);
}