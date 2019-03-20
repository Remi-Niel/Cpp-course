#include "main.ih"

void readInput(Scanner &scanner, vector<string> &words)
{
    bool done = false;

    while (!done)
    {
        switch (scanner.lex())
        {
            case WORD:
                words.push_back(scanner.matched());
                break;
            case DONE:
                done = true;
                break;
            default:
                cerr << "This should not be possible\n"; 
        }
    }
}
