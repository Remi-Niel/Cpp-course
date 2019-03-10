#include <iostream>
#include "Scanner.h"

using namespace std;

int main()
try
{
    Scanner scanner;

    while(scanner.lex())
        ;
}
catch(...)
{
    return 1;
}