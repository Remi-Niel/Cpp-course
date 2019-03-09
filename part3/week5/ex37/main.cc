#include <iostream>
#include "Scanner.h"

using namespace std;

int main()
{
    Scanner scanner;

    while (true)
    {
        size_t token = scanner.lex();
        switch (token)
        {
            case DONE:
                return 0; //done
            case SUBL:
                cout << scanner.matched();
                break;
            case BLANK:
                cout << ' ';
                break;
            case ENDL:
                cout << '\n';
                break;
            default:
                cerr << "something went wrong\n";
        }
    }

}