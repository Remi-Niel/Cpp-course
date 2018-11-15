#include "strings.ih"

void Strings::at(char const *&str, std::size_t idx) const
{
	if (idx < d_size)
    	str = d_str[idx].c_str();
    else
    	str = "";
}