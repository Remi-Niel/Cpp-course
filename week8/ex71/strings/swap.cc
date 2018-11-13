#include "strings.ih"

void Strings::swap(Strings &other)
{
    char bytes[sizeof(Strings)];
    memcpy(bytes, this, sizeof(Strings));
    memcpy(reinterpret_cast<char*>(this), &other, sizeof(Strings));
    memcpy(reinterpret_cast<char*>(&other), bytes, sizeof(Strings));
}
