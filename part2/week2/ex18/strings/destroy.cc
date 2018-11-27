#include "strings.ih"

//This member is exception safe because delete[] has no-throw
//guarentee, hence destroy() also has a no-throw guarentee.

void Strings::destroy()
{
    delete[] d_str;
}
