#include "converter.ih"

void Converter::processByte(size_t &idx, uint8_t &byte, char &base)
{

    for (idx = 0; idx < 4; ++idx)
    {
        input.get(base);    //Read next base
        if (input.eof() || base == '\n')    //Stop if eof
            break;

        //Write base to bits, however if enumVal encounters a
        //nonlegal base it exits the program
        setBits(byte, idx, enumVal(base));
    }

    //left shift bits if less than 4 character were processed
    byte = byte << ((4 - idx) * 2);
}
