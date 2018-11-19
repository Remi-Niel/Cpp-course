#include "in.ih"

Strings::In::In(Strings *str, void (*funPtr)(std::ostream &out, Strings const &str, size_t idx))
{
    d_str = str;
    d_begin = 0;
    d_end = str->size();
    d_del = "";
    d_funPtr = funPtr;
}
