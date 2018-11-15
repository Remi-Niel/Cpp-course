#include "strings.ih"

Strings::Strings(int argc, char **argv)
{
	d_size = (size_t) argc;
	d_str = new string[argc];

	for (size_t idx = 0; idx != (size_t) argc; ++idx)
		d_str[idx] = argv[idx];
}
