#include "strings.ih"

istream &Strings::extractFrom(istream &in)
{
	string inputStr;

	while (getline(in, inputStr))
		add(inputStr);

    return in;
}
