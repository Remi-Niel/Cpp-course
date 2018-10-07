#include "strings.ih"

Strings::Strings(istream &in)
//:
{
	d_size = 0;
	string inputStr;

	while (getline(in, inputStr))
		add(inputStr);
}
