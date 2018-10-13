#include "strings.ih"

Strings::Strings(char **environ)
{
	d_size = 0;
	d_capacity = 0;
	reserve(1);
	
	while (environ[d_size] != 0)
		add(environ[d_size]);
}
