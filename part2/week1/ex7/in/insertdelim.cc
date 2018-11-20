#include "in.ih"

void Strings::In::insertDelim(std::ostream &out, Strings const &str, size_t idx)
{
    out << (idx + 1 == d_end ? "\n" : d_del);
}
