#include "sort.ih"

Sort::Sort(int (*compar)(string **pp_str1, string **pp_str2))
:   cmpFunc {compar}
{
}
