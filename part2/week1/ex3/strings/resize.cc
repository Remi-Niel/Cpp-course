#include "strings.ih"

void Strings::resize(std::size_t count)
{
    if (d_size < count)
    {
        reserve(count);

        for (string **start = d_str + d_size; start != d_str + count; ++start)
            *start = new string;
    }

    if (d_size > count)
        for (string **start = d_str + count; start != d_str + d_size; ++start)
            delete *start;

    d_size = count;
}