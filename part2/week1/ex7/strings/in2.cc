#include "strings.ih"

Strings::In Strings::in(char const *sep, size_t start)
{
    return Strings::In{this, sep, start};
}
