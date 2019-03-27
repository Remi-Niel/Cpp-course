#include "main.ih"

int main(int argc, char **argv)
{
    Parser *parser;

    if (argc != 1)
        parser = new Parser(argv[1][0]);
    else
        parser = new Parser();
    
    int result = parser->parse();
    
    delete parser;

    return result == 0 ? 0 : 1;
}
