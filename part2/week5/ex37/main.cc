#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<string, size_t> counts;

	string input;
	while (cin >> input)
		++counts[input];

	for (auto &[key, val] : counts)
		cout << key << " (# " << val << ")\n";
	
}