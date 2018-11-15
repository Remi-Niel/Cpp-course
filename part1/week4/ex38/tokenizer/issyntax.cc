#include "tokenizer.ih"

bool Tokenizer::is_syntax(string const &str)
{
    if (str.find_first_not_of("-1234567890") == string::npos)
        return false;

    return true;
}