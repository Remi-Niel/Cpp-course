#include "showexcepts.ih"

// This function mimics a function with a throwlist(int, string) behavior.
// When a int or string is caught it is automatically rethrown to the 
// calling function, when something else is caught it throws a bad_exception.
void ShowExcepts::as_throwlist()
try
{
    (*d_thrower)();
}
catch(int exception)
{
    throw;
}
catch(string exception)
{
    throw;
}
catch(...)
{
    throw bad_exception();
}
