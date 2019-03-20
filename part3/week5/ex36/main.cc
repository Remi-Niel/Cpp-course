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
                cout << "INT: "; 
                break;
            case FLOAT:
                cout << "FLOAT: ";
                break;
            case OPER:
                cout << "OPER: ";
                break;
            case WORD:
                cout << "WORD: ";
                break;
            case STRING:
                cout << "STRING: ";
                break;
            case ENDL:
                cout << "ENDL";
                break;
            default:
                cout << token << ": ";
        }
        cout << scanner.matched() << '\n';
    }

}