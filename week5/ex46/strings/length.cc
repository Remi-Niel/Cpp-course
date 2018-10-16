#include "strings.ih"

size_t Strings::length(char **data) const
{   
    size_t idx = 0;
    
    while (data[idx] != 0)
        ++idx;

    return idx;
}