#include "arg.ih"

size_t Arg::option(std::string const &options) const
{
    size_t count = 0;
    for (char const &opt : options)
        count += option(opt);
    
    return count;
}