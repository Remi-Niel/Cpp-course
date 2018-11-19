#include "strings.ih"

string &Strings::operator[](size_t index)
{
    return at(index);
}
