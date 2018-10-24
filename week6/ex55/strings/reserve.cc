#include "strings.ih"

void Strings::reserve(std::size_t n){
    if (n > d_capacity)
    {
        string *newStr = rawStrings(n);

        for (size_t idx = d_size - 1; idx--; )
            new(newStr + idx) string{d_str[idx]};

        destroy();
        
        d_str = newStr;
        d_capacity = n;
    }
}
