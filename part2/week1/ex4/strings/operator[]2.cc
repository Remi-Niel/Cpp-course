#include "strings.ih"

string const &Strings::operator[](size_t index) const
{
    return at(index);
}
