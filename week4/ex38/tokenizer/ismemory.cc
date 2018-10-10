#include "tokenizer.ih"

bool Tokenizer::is_memory(string const &str)
{
     if (str[0] != '@')
        return false;

    d_value = stoi(str.substr(1));
    return true;
}