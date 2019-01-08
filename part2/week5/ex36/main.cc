#include <set>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	// set is ordered so output will be aswell
	set<string> wordset;
	string input;

	// grab all strings fropm input and push them onto the priority queue
	while (cin >> input)
		wordset.insert(input);

	// display unique words ordered
	for (string const &str : wordset)
		cout << str << "\n";
}