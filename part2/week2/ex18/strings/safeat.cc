#include "strings.ih"

//Basic guarantee: no dynamically allocated data
//Strong guarantee: no data is adjusted (const member)
//Exception neutral: exceptions are propagated to the caller
std::string &Strings::safeAt(size_t idx) const
{
    if (idx < 0 || idx >= d_size)
        throw std::invalid_argument("Array bound excess");

    return *d_str[idx];
}
