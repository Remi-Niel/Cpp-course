#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	map<string, size_t> wordcountmap;

	string input;
	while (cin >> input)
	{
			pair<map<string, size_t>::iterator, bool> ret;
			ret = wordcountmap.insert(pair<string, size_t>(input, 1));
			if (ret.second == false)
				wordcountmap[input]++;
	}

	for (map<string,size_t>::iterator iter = wordcountmap.begin();
									  iter != wordcountmap.end(); ++iter)
	{
		cout << iter->first << ": " << iter->second << '\n';
	}
}