#include "strings.ih"

stringsData Strings::release()
{
	stringsData data;
	data.size = d_size;
	data.capacity = d_capacity;
	data.strings = d_str;

	d_size = 0;
	d_capacity = 1;
	d_str = new string *[1];

	return data;
}
