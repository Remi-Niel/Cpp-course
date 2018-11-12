#include "strings.ih"

void Strings::enlarge(bool copy)
{
	if(copy)
	{
		string *newArr = new string[d_size + 1];

		for (string *oldStr = d_str, *newStr = newArr; oldStr != d_str + d_size; ++oldStr, ++newStr)
			*newStr = *oldStr;

		delete[] d_str;
		d_str = newArr;
	}
	else
	{
		string *newArr = new string[d_size + 1];

		for (string *oldStr = d_str, *newStr = newArr; oldStr != d_str + d_size; ++oldStr, ++newStr)
			*newStr = move(*oldStr);

		delete[] d_str;
		d_str = newArr;
	}
}
