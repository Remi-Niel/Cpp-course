#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	list<string> strings;
	string input;

	while (cin >> input)
	{
		strings.push_back(input);
	}

	strings.sort();
	
	for (list<string>::iterator iter = strings.begin(); 
								iter != strings.end(); ++iter)
	{
		cout << *iter << '\n';
	}
}