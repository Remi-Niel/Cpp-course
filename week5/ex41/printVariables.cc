#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	for (char **begin = argv, **end = argv + argc; begin != end; ++begin)
	{
		cout << *begin << '\n';
	}

	for (extern char **environ; *environ; ++environ)
	{
		cout << *environ << '\n';
	}
}