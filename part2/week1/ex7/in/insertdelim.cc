#include "in.ih"

void Strings::In::insertDelim(std::ostream &out, Strings const &str, size_t idx)
{
    out << (idx + 1 == str.size() ? "\n" : d_del);
}
