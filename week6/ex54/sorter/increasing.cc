#include "sorter.ih"

int Sorter::increasing(string **str1, string **str2)
{
    return (*str1)->compare(**str2);
}