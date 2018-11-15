#include "strings.ih"

bool Strings::equals(Strings const &str) const
{
    if (d_size != str.d_size)
        return false;

    for (size_t idx = 0; idx != d_size; ++idx)
        if (at(idx) != str[idx])
            return false;
            
    return true;
}
