#include "strings.ih"

//Basic guarantee: everything allocated (d_str) is accessable after the member is 
//done or not actually allocated at all hence basic guarantee is provided.
//Strong guarantee: nothing existed beforehand so nothing to rollback to.
//Exception neutral: exceptions are propagated to the caller.
Strings::Strings(int argc, char *argv[])
    : Strings()
{
    for (size_t begin = 0, end = argc; begin != end; ++begin)
        add(argv[begin]);
}
