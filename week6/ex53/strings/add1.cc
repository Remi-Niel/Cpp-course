#include "strings.ih"

void Strings::add(char *str)
{
	if (d_size == d_capacity)
		reserve(d_capacity * 2);
	
	d_str[d_size] = new string(str);
	++d_size;
}
