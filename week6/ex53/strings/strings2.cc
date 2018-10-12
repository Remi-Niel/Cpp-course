#include "strings.ih"

Strings::Strings(char **environ)
//:
{
	d_size = 0;
	d_capacity = 1;
	d_str = new string *[1];

	while (environ[d_size] != 0)
		add(environ[d_size]);
}
