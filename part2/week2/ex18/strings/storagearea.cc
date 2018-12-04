#include "strings.ih"

//Basic guarantee: enlarged returns pointer to allocated data,
//hence caller is responsible for data: no leaks.
//Strong guarantee: since enlarged() provides the strong guarantee,
// and storageArea() does not directly make any changes 

string **Strings::storageArea()
{
    if (d_size + 1 < d_capacity)        // enough room?
        return d_str;                   // return the current memory block

    d_capacity <<= 1;                   // double the capacity
    
    return enlarged();                  // return ptr to the enlarged space 

}

