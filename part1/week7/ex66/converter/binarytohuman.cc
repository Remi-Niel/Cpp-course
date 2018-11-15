#include "converter.ih"

void Converter::binaryToHuman(ofstream &output, size_t offset)
{
    uint8_t bits;
    size_t limit = 4; //Default amount of characters in a byte

    input.read(reinterpret_cast<char *>(&bits), sizeof(bits));
    while (!input.eof())
    {
        //If the final set of bases has been read
        if (input.peek(), input.eof()) 
            limit = offset;  //Update amount of characters in the bitset
        
        for (size_t idx = 0; idx != limit; ++idx) //Output characters in bitset
            output.put(valueOf(bits, idx));
        
        input.read(reinterpret_cast<char *>(&bits), sizeof(bits));
    }
}
