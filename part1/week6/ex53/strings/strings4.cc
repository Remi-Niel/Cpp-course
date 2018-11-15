#include "strings.ih"

Strings::Strings()
{
	d_size = 0;
	d_capacity = 0;
	reserve(1);
}
