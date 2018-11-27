#include "showexcepts.ih"

void ShowExcepts::as_noexcept()
try
{
    (*d_thrower)();
}
catch(...)
{
    terminate();
}