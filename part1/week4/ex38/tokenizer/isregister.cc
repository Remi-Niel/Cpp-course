#include "tokenizer.ih"

bool Tokenizer::is_register(string const &str)
{
    if (str.size() != 1)
        return false;

    //check if it is a letter
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        d_value = str[0] - 'a';
        return true;
    }

    return false;
}