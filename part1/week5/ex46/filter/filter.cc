#include "filter.ih"

Filter::Filter()
	: d_str(Strings(cin))
{
	set_bounds();
}
