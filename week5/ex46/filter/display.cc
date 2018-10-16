#include "filter.ih"

void Filter::display()
{
	string const *start = str.data();

	size_t size = str.size();

	string const *end = start + size -1;

	while (end->find_first_not_of(" \t") == string::npos)
		--end;

	while (start->find_first_not_of(" \t") == string::npos)
		++start;

	for (; start != end + 1; ++start)
		cout << *start << '\n';
}
