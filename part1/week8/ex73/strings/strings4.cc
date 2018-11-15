#include "strings.ih"

Strings::Strings()
{
	d_str = 0;
	d_size = 0;
	d_capacity = 0;
	reserve(1);
}
