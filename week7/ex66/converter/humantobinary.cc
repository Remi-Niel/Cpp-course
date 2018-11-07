#include "converter.ih"

void Converter::humanToBinary(ofstream &output)
{
    char base = 0;
    uint8_t bits = 0;
    while (true)
    {
        size_t idx;
        for (idx = 0; idx < 4; ++idx)
        {
            input.get(base);    //Read next base
            if (input.eof() || base == '\n')    //Stop if eof
                break;
            setBits(bits, idx, enumVal(base)); //Write base to bits
        }
        
        if (idx > 0)
        {
            bits = bits << ((4-idx)*2); //left shift bits if less than 4 character were processed
            output.write(reinterpret_cast<char *>(&bits), sizeof(bits));
        }

        if (input.eof() || base == '\n')
        {
            idx = (idx == 0) ? 4 : idx; //If idx is 0 the last written block contained 4 bases
            output.seekp(1);
            output.put(idx); //Write amount of bases in last block to the second byte
            break;
        }
    }
}
