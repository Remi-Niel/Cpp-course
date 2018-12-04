#include "strings.ih"

// Basic guarentee: the allocated memory is either not allocated if new throws an exception
// or the allocated memory is later removed by the program.
// Strong guarentee: nothing is overwritten or removed hence rolling back is not necesarry
// Exception neutral: exceptions are passed to the caller
string **Strings::rawPointers(size_t nPointers)
{
    return new string *[nPointers];
}
