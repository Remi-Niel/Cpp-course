#include "strings.ih"

string &Strings::at_index(size_t idx) const
{
    static string wrong;
    return (idx >= d_size ? *(new string(wrong)) : *d_str[idx]);
}