#include "strings.ih"

void Strings::reserve(std::size_t n){
    if (d_capacity == 0)
    {
        d_str = new string*[n];
        d_capacity = n;
        return;
    }
    
    if (n > d_capacity)
    {
        string **newStr = new string *[n];

        for (string **old = d_str, **newArr = newStr;
             old != d_str + d_size;
             ++old, ++newArr)
        {
            *newArr = *old;
        }

        if (d_capacity > 0)
            delete[] d_str;
        
        d_str = newStr;
        d_capacity = n;
    }
}
