#include "main.ih"

int main(int argc, char **argv)
try
{
    Parser parser;

    parser.parse();
}
catch (...)
{
    return 1;
}
