#include "strings.ih"

Strings &Strings::operator=(Strings const &rvalue)
{
    cout << "COPY\n";
    Strings copy(rvalue);
    swap(copy);
    return *this;
}
