#include "filter.ih"

void Filter::set_bounds()
{
    d_first_line = d_str.data();
    size_t size = d_str.size();

    d_last_line = d_first_line + size - 1;

    while (d_last_line->find_first_not_of(" \t") == string::npos)
        --d_last_line;

    while (d_first_line->find_first_not_of(" \t") == string::npos)
        ++d_first_line;
}