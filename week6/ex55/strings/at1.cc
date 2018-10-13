#include "strings.ih"

void Strings::at(std::string &str, std::size_t idx) const
{
	if (idx < d_size)
		str = d_str[idx];
	else
    	str = "";
}