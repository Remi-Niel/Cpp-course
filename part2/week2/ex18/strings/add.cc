#include "strings.ih"

// Basic guarentee: tmp is deleted if an exception occurs while reserving new memory
// the previous data is removed if it has been copied into a new location.

// Strong guarentee: there are 2 cases, either there still is enough memory,
// in this case the string is added and old data does not have to be removed.
// Or there is not enough memory and new memory has to be reserved, in this
// case the data is only removed when everything has been copied correctly.
// Hence commit or rollback.

// Exception neutral: exceptions are propagated to the caller.
void Strings::add(string const &next)
{
    string **tmp = nullptr;

    try
    {
        tmp = storageArea();
        tmp[d_size] = new string(next);
    }
    catch(...)
    {
        delete[] tmp;
        throw;
    }

    if (tmp != d_str)               // destroy old memory if new storageArea 
    {                               // was allocated
        destroy();                  // destroy the old string * array
        d_str = tmp;
    }

    ++d_size;
}
