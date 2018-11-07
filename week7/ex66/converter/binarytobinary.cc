#include "converter.ih"

void Converter::binaryToBinary(ofstream &output)
{
    uint8_t bits;
    input.read(reinterpret_cast<char *>(&bits), sizeof(bits));
    while (!input.eof())
    {
        output.write(reinterpret_cast<char *>(&bits), sizeof(bits));
        input.read(reinterpret_cast<char *>(&bits), sizeof(bits));
    }
}
