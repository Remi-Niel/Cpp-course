#include "strings.ih"

Strings::Strings(istream &in)
{
	d_size = 0;
	d_capacity = 0;
	reserve(1);
	string inputStr;

	while (getline(in, inputStr))
		add(inputStr);
}
