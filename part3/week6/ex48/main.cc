#include "main.ih"

#include "parser/parser.h"

int main(int argc, char **argv)
try
{
    Parser parser;
    Scanner scan;

    int token;
    while ((token = scan.lex()) != Parser::NEWLINE)
    {
        cout << token << "\n";
    }

    // cout << "? ";
    // if ( parser.parse() == 1)
    //     cout << "parser error\n";
    // else
    //     cout << "parser ok\n";
}
catch (...)
{
    return 1;
}
