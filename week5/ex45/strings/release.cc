#include "strings.ih"

stringsData Strings::release()
{
	stringsData data = { d_size, d_str };

	d_size = 0;
	d_str = {};

	return data;
}
