#include "strings.ih"

Strings::Strings(char **environ)
//:
{
	d_size = 0;

	while (environ[d_size] != 0)
		add(environ[d_size]);
}
