#include "main.ih"

int main(int argc, char **argv, char** environ)
{
	Strings str1{argc, argv};
	Strings str2{environ};

	cout << boolalpha << (str1 == str1) << ", " << (str1 == str2) << ", " << (str1 != str1) << ", " << (str1 != str2) << '\n';
}