#include "converter.ih"

void Converter::binaryOutput(string outputFile)
{
    ofstream output{outputFile};

    char type, offset;

    //Determine input type, binary starts with a '0'. Human readable cannot start with a '0'
    type = input.peek(); 

    if (type == BINARY) //Binary to binary simply copies the file byte by byte
    {
        input.get(type);
        input.get(offset); //Get the amount of bases in the final byte
        output.put(BINARY);
        output.put(offset);

        binaryToBinary(output);
    }
    else   
    {
        output.put(BINARY);
        output.put('E');    //Placeholder for the amount of bases in the final byte
        humanToBinary(output);
    }
}
