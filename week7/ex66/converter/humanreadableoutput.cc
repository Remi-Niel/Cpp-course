#include "converter.ih"

void Converter::humanReadableOutput(string outputFile)
{
    ofstream output{outputFile};

    char type, offset;

    type = input.peek();

    if (type == BINARY)
    {
        input.get(type);
        input.get(offset);
        binaryToHuman(output, offset);
    }
    else
        humanToHuman(output);
}
