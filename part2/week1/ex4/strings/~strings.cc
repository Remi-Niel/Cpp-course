#include "strings.ih"

Strings::~Strings()
{
	for (string **start = d_str; start != d_str + d_capacity; ++start)
		delete *start;

	delete[] d_str;
}