#include "converter.ih"

void Converter::humanToHuman(ofstream &output)
{
    char base;
    input.get(base);
    while (!input.eof())
    {
        enumVal(base); //Make sure character is legal
        output.put(base);
        input.get(base);
    }
}
