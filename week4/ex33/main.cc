#include "main.ih"

int main(int argc, char **argv)
try
{
	Person p;
	p.extract(cin);
	p.insert(cout);
}
catch (...)
{
    return 1;
}
