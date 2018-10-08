#include "strings.ih"

void Strings::swapStrings(Strings &left, Strings &right)
{
    size_t size1 = left.d_size;
    string *string1 = left.d_str;

    left.d_size = right.d_size;
    left.d_str = right.d_str;

    right.d_size = size1;
    right.d_str = string1;
}