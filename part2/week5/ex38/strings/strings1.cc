#include "strings.ih"

Strings::Strings(int argc, char **argv)
{
    d_strings.reserve(argc);
    
    for (size_t idx = 0; idx != static_cast<size_t>(argc); ++idx)
        d_strings.push_back(argv[idx]);
}