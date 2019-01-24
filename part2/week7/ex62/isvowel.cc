#include "isvowel.h"

int isvowel(int c)
{
    return 
    (
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
        c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
    );
}