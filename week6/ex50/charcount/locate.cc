#include "charcount.ih"


// Locate the index, of not found return insert / append.
int CharCount::locate(char chin) const
{
    for (size_t idx = 0; idx < d_charinfo.nChar; ++idx)
    {
        if (d_charinfo.ptr[idx].ch > chin)
            return INSERT;
        
        if (d_charinfo.ptr[idx].ch == chin)
            return static_cast<int>(idx);
    }

    return APPEND;
}