#include "strings.ih"

void Strings::destroy()
{

    if (d_capacity > 0)
    {
        for (string *end = d_str + d_size; end-- != d_str; )
            end->~string();

        operator delete(d_str);
    }
}
