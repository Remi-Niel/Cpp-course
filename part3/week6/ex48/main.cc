#include "main.ih"

#include "parser/parser.h"

int main(int argc, char **argv)
try
{
    Parser parser;
    Scanner scan;

    if (parser.parse() != 1)
        cout << "parsed ok!\n";
    else
        cout << "parser error!\n";

}
catch (...)
{
    return 1;
}
