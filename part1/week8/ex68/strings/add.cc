#include "strings.ih"

void Strings::add(string const &str)
{
	(this->*enlargeFunc)();
	d_str[d_size] = str;
	++d_size;
}
