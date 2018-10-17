#ifndef INCLUDED_SORT_
#define INCLUDED_SORT_
#include <string>

class Sorter
{
    int (*cmpFunc)(std::string **pp_str1, std::string **pp_str2);

    public:
        Sorter(int (*compar)(std::string **pp_str1, std::string **pp_str2));
        void sort(std::string **strArrays, size_t size);
        static int increasing(std::string **pp_str1, std::string **pp_str2);
        static int nocasedec(std::string **pp_str1, std::string **pp_str2);
        
};
#endif
