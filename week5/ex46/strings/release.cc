#include "strings.ih"

stringsData Strings::release()
{
	stringsData data;
	data.size = d_size;
	data.strings = d_str;

	d_size = 0;
	d_str = {};

	return data;
}
