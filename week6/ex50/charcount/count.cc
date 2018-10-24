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
        
        (this->*s_updater[locate(chin)])(chin);
    }

    return count;
}