#include "strings.ih"

//Basic guarantee: no memory is allocated
//Strong guarantee: no data is changed
//Exception neutral: exceptions are forwarded to the caller

std::string const &Strings::at(size_t idx) const
try
{
    return safeAt(idx);
}catch(...)
{
    throw;
}
