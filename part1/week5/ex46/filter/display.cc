#include "filter.ih"

void Filter::display()
{
	string const *start = d_first_line;
	
	for (; start != d_last_line + 1; ++start)
		cout << *start << '\n';
}
