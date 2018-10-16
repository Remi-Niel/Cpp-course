#ifndef INCLUDED_SORT_
#define INCLUDED_SORT_

#include "sort.ih"

class Sort
{
    int (*cmpFunc)(string **pp_str1, string **pp_str2);

    public:
        Sort(int (*compar)(string **pp_str1, string **pp_str2));
        void sort(string **strArrays, size_t size);
        static int increasing(string **pp_str1, string **pp_str2);
        static int nocasedec(string **pp_str1, string **pp_str2);
        
};
#endif
