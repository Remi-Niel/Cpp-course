#include "strings.ih"

Strings::In Strings::in(char const *sep)
{
    return Strings::In{this, sep};
}
