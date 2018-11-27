#include "strings.ih"

//Basic guarantee: allocated memory is reachable when the member is done (d_str)
//Strong guarentee: old strings are only deleted if reserve didn't throw exceptions
//Exception neutral: exceptions are propagated to the caller.
void Strings::resize(size_t newSize)
{
    try
    {
        reserve(newSize);           // make sure there's enough memory

        if (newSize > d_size)       // enlarging? initialize new strings
        {
            for (; d_size != newSize; ++d_size)
                d_str[d_size] = new string;
        }
        else if (newSize < d_size)  // shrinking? remove excess strings
        {
            for (; d_size-- != newSize; )
                delete d_str[d_size];
        }
    }
    catch(...)
    {
        throw;
    }
}
