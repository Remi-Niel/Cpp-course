#include "in.ih"

Strings::In::In(Strings *str, void (*funPtr)(std::ostream &out, Strings const &str, size_t idx), size_t begin, size_t end)
{
    d_str = str;
    d_begin = begin;
    d_end = end;
    d_del = "";
    d_funPtr = funPtr;
}
