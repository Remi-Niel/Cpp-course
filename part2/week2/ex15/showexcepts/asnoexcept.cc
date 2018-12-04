#include "showexcepts.ih"

// Mimics a function that has a noexcept specifier.
// When something is thrown and not caught it will cause terminate() to
// be called.
void ShowExcepts::as_noexcept()
try
{
    (*d_thrower)();
}
catch(...)
{
    terminate();
}