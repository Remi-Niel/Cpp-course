#include "main.ih"

void showChar(Char const &toshow)
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