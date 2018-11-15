#include "tokenizer.ih"

bool Tokenizer::nextItem()
{
    while (not read())          // no more info about this line?
    {
        if (cin.eof())
        {
            cout << "Unexpected EOF at line " << d_line << '\n';
            return false;
        }
        reset();
    }

    return true;
}   