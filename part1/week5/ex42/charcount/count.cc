#include "charcount.ih"

#include <iostream>

static void showChar(Char const &toshow)
{    
    switch(toshow.ch)
    {
        case ' ':
            cout << "' ': ";
        break;

        case '\n':
            cout << "'\\n': ";
        break;

        case '\t':
            cout << "'\\t': ";
        break;

        default:
            if (isprint(toshow.ch))
                cout << toshow.ch << ": ";
            else
                cout << static_cast<size_t>(toshow.ch) << ": ";
        break;
    }

    cout << toshow.count << "\n";
}

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

        cout << "updated with " << idx << endl;
        for (size_t idx = 0; idx < d_charinfo.nChar; ++idx)
        {
            showChar(d_charinfo.ptr[idx]);
        }
    }

    return count;
}