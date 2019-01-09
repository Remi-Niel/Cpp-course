#include "strings.ih"

size_t Strings::length(char **data)
{
    size_t len = 0;

    while (data[len])
        ++len;

    return len;
}