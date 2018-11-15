#include "strings.ih"

ostream &Strings::insertInto(ostream &out)
{
    for (size_t idx = 0; idx != d_size; ++idx)
        out << at(idx) << '\n';

    return out;
}
