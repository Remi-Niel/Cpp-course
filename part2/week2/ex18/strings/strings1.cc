#include "strings.ih"

//Basic guarantee: allocated data (d_str) is either not allocated if
//<new> throws an exception, or is allocated in which case it can be 
//destroyed by the destructor. Hence there are no leaks;
//Strong guarantee: nothing to rollback to.
//Exception neutral: exceptions are propagated to the caller.
Strings::Strings()
try
{
    d_str =rawPointers(1);
}
catch(bad_alloc)
{}
