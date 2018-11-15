#include "strings.ih"

Strings::Strings(char **environ)
//:
{
	d_size = 0;
	d_str = {};

	while (environ[d_size] != 0)
		add(environ[d_size]);
}
