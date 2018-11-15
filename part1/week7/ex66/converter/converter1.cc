#include "converter.ih"

Converter::Converter(string const &inputFile)
{
    input = ifstream(inputFile);
}
