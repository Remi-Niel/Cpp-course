#include "strings.ih"

Strings::Strings(char **environ)
	: Strings(length(environ), environ)
{ }
