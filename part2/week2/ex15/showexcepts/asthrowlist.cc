#include "showexcepts.ih"

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
