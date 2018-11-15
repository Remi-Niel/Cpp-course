#include "converter.ih"

void Converter::binaryOutput(string const &outputFile)
{
    char type;

    //Determine input type, binary starts with a '0'. 
    //Human readable cannot start with a '0'
    type = input.peek(); 

    if (type == BINARY) //Binary to binary simply copies the file byte by byte
    {
        cerr << "Your are trying to convert binary to binary\n";
        exit(1);
    }

    ofstream output{outputFile};
    
    output.put(BINARY);
    output.put('E');    //Placeholder for the amount of bases in the final byte
    humanToBinary(output);
    
}
