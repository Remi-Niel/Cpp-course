#include "strings.ih"

std::string &Strings::safeAt(size_t idx) const
{
    if (idx >= d_size)
        throw std::invalid_argument("Array bound excess");

    return *d_str[idx];
}
