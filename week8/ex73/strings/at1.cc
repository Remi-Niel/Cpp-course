#include "strings.ih"

string const &Strings::at(size_t idx) const
{
	return at_index(idx);
}