#include "bitset.ih"

string operator "" _bits(char const *literal)
{
    string rval{ literal };
    
    if (rval.find_first_not_of("01") != string::npos)
    {
        cerr << "Literal contains characters other than '1' or '0'.\n";
        return "";
    }
    
    return rval;
}