#include "strings.ih"

Strings::Strings(istream &in)
//:
{
	d_size = 0;
	d_capacity = 1;
	d_str = new string *[1];
	string inputStr;

	while (getline(in, inputStr))
		add(inputStr);
}
