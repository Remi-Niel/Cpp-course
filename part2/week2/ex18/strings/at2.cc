#include "strings.ih"

//Basic guarantee: no memory is allocated
//Strong guarantee: no data is changed
//Exception neutral: exceptions are forwarded to the caller

std::string &Strings::at(size_t idx)
{
    return safeAt(idx);
}
