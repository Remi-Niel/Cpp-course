#include "strings.ih"

string *Strings::rawStrings(size_t count)
{
    return static_cast<string *>(operator new(count * sizeof(string)));
}
