#include "strings.ih"

//Basic guarantee: either ret is not allocated if an exception occurs
// or it is returned after which it is the responsibility of the caller.
//Strong: previous data is not overwritten hence nothing to rollback;
//Exception neutral: encountered exceptions are propagated to the caller.

string **Strings::enlarged()
{
    string **ret;
    
    // new block, doubling the # pointers
    string **ret = rawPointers(d_capacity);
    
    // copy the existing pointers
    for (size_t idx = 0; idx != d_size; ++idx)
        ret[idx] = d_str[idx];

    return ret;
}
