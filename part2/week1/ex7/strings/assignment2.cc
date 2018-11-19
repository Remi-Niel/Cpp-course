#include "strings.ih"

Strings &Strings::operator=(Strings &&tmp)
{
    cout << "SWAP\n";
    swap(tmp);
    return *this;
}
