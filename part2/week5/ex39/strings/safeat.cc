#include "strings.ih"

string Strings::safeAt(size_t idx) const
{
    if (idx >= d_strings.size())
        throw std::out_of_range("Array bound excess");

    return *d_strings.at(idx);
}
