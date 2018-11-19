#include "in.ih"

Strings::In::In(Strings *str, char const *delim, size_t begin)
{
    d_str = str;
    d_begin = begin;
    d_end = str->size();
    d_del = delim;
    d_funPtr = nullptr; //set to 0 to indicate insertDelim should be used
}
