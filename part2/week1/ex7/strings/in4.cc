#include "strings.ih"

Strings::In Strings::in(void (*funPtr)(std::ostream &out, Strings const &str, size_t idx))
{
    return Strings::In{this, funPtr};
}
