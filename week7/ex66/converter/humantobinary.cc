#include "converter.ih"

void Converter::humanToBinary(ofstream &output)
{
    char base = 0;
    uint8_t byte = 0;

    while (true)
    {
        size_t idx;
        
        processByte(idx, byte, base);

        if (idx > 0)
            output.write(reinterpret_cast<char *>(&byte), sizeof(byte));

        if (input.eof() || base == '\n')
        {
            finishBinary(idx, output);
            break;
        }
    }
}
