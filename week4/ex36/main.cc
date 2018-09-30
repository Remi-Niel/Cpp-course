#include "main.ih"

int main(int argc, char **argv)
try
{
	Memory mem;

	mem.store(0, 1);
	mem.store(12, 5);

	cout << mem.load(0) << '\n';
	cout << mem.load(12) << '\n';
	cout << mem.load(9) << '\n';
}
catch (...)
{
    return 1;
}
