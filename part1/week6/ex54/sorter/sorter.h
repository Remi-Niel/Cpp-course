#ifndef INCLUDED_SORT_
#define INCLUDED_SORT_
#include <string>

typedef int (*d_Comparer)(std::string **pp_str1, std::string **pp_str2);

class Sorter
{
    d_Comparer d_cmpFunc;

    public:
        Sorter(d_Comparer cmpFunc);
        void sort(std::string **strArrays, size_t size);
        static int increasing(std::string **pp_str1, std::string **pp_str2);
        static int nocasedec(std::string **pp_str1, std::string **pp_str2);
        
    private:
        static int char_compare(char c1, char c2);
};

#endif
