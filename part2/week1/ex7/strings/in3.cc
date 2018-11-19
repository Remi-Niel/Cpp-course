#include "strings.ih"

Strings::In Strings::in(char const *sep, size_t start, size_t end)
{
    return Strings::In{this, sep, start, end};
}
