#include "strings.ih"

// Basic guarentee: memory is destroyed if no longer in use, hence no leaks
// Strong guarentee: The old data is only removed after all operations which can
// throw exceptions are done, hence commit or rollback.
// Exception neutral: exceptions are propagated to the caller.
void Strings::add(string const &next)
{
    string **tmp;

    try
    {
        tmp = storageArea();
        tmp[d_size] = new string(next);
    }
    catch(...)
    {
        throw;
    }

    if (tmp != d_str)               // destroy old memory if new storageArea 
    {                               // was allocated
        destroy();                  // destroy the old string * array
        d_str = tmp;
    }

    ++d_size;
}
