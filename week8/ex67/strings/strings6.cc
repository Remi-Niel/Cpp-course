#include "strings.ih"

Strings::Strings(Strings &&tmp)
:
    d_str(tmp.d_str),
    d_size(tmp.d_size),
    d_capacity(tmp.d_capacity)
{
    tmp.d_str = 0;
}
