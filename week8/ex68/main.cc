#include "main.ih"

int main(int argc, char **argv, char **environ)
{
	Strings strings;

	if (argc == 2)
		strings = Strings(stoul(argv[1]), true);
	else
		strings = Strings(stoul(argv[1]), false);

	strings.iterate(environ); 

}
