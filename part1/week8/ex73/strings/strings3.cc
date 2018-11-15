#include "strings.ih"

Strings::Strings(istream &in)
	: Strings()
{
	string inputStr;

	while (getline(in, inputStr))
		add(inputStr);
}
