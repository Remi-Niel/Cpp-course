#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	vector<string> strings;
	string input = "";

	while (getline(cin, input, ' '))
	{
		if (input == "\n")
			continue;

		vector<string>::const_iterator idx = strings.begin();
		for (; idx < strings.end(); ++idx)
		{
			if (input.compare(*idx) <= 0)
			{
				strings.insert(idx, input);
				break;
			}
		}

		if (idx == strings.end())
			strings.insert(idx, input);
	}

	for (size_t idx = 0; idx < strings.size(); ++idx)
		cout << strings.at(idx) << '\n';
}