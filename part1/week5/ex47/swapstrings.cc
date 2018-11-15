#include "main.ih"

void swapStrings(Strings &left, Strings &right)
{
    Strings tmp = left;
    left = right;
    right = tmp;
}