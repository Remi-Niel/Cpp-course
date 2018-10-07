#include "charcount.ih"

size_t CharCount::count(std::istream& in)
{
    size_t count = 0;
    while(true)
    {
        char chin = in.get();

        if(chin == char_traits<char>::eof())
            break;
        
        ++count;
        int idx = locate(chin);
        
        if(idx == APPEND)
            append(chin);
        else if(idx == INSERT)
            insert(chin);
        else
            ++d_charinfo.ptr[idx].count;
    }

    return count;
}