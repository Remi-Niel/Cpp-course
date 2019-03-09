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
                return 0;
            case INT:
                cout << "INT: " << scanner.matched() << '\n';
                break;
            case FLOAT:
                cout << "FLOAT: " << scanner.matched() << '\n';
                break;
            case OPER:
                cout << "OPER: " << scanner.matched() << '\n';
                break;
            case WORD:
                cout << "WORD: " << scanner.matched() << '\n';
                break;
            case STRING:
                cout << "STRING: " << scanner.matched() << '\n';
                break;
            case ENDL:
                cout << "ENDL: " << scanner.matched() << "\\n";
                break;
            default:
                cout << token << ": " << scanner.matched() << '\n';
        }
    }

}