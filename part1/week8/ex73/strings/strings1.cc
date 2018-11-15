#include "strings.ih"

Strings::Strings(int argc, char **argv)
{
	d_size = 0;
	d_capacity = 0;
	reserve((size_t) argc);

	for (char **tmp = argv; tmp != argv + (size_t) argc; ++tmp)
		add(*tmp);

}
