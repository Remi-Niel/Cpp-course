#include "main.ih"

extern char **environ;

void fun(ostream &out, Strings const &str, size_t idx)
{
	out << (idx + 1 == str.size() ? "\n" : ", ");
}

int main(int argc, char **argv)
{
	Strings env(environ);
	cout << env.in(",\n", 1, 5) << '\n';

	cout << env.in(fun, env.size() -4);
	cout << "done\n";
}