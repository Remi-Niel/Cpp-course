#include "taskthreads.ih"

int isvowel(int ch)
{
    static string vowels{"aeiou"};
    return vowels.find_first_of(tolower(ch)) != string::npos;
}