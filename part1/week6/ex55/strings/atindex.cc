#include "strings.ih"

string &Strings::at_index(size_t idx) const
{
    static string wrong;
    return (idx >= d_size ? wrong : d_str[idx]);
}