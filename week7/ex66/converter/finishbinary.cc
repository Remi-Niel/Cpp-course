#include "converter.ih"

void Converter::finishBinary(size_t amount, ofstream &output)
{
    //If the idx is 0 the last written block has to be full and therefor
    // contains 4 bases
    amount = (amount == 0) ? 4 : amount;
    output.seekp(1);
    output.put(amount); //Write amount of bases in last block to the second byte
}
