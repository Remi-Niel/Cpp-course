#include "converter.ih"

void Converter::humanReadableOutput(string const &outputFile)
{
    char type, offset;

    type = input.peek();

    if (type != BINARY)
    {
        cerr << "You are trying to convert human readable to human readable\n";
        exit(1);
    }

    ofstream output{outputFile};

    input.get(type);
    input.get(offset);
    binaryToHuman(output, offset);
    
    
    
}
