#include "strings.ih"

void Strings::add(string str)
{
	cout<<"test";
	string *newArr = new string[d_size + 1];

	for (string *oldStr = d_str, *newStr = newArr; oldStr != d_str + d_size; ++oldStr, ++newStr)
		*newStr = *oldStr;

	newArr[d_size] = str;

	delete[] d_str;
	d_str = newArr;

	cout << d_str[d_size] << '\n';

	++d_size;
}
