#include "converter.ih"

Converter::Converter(string inputFile)
{
    input = ifstream(inputFile);
}
