#ifndef INCLUDED_CONVERTER_
#define INCLUDED_CONVERTER_

#include <fstream>


enum nucleobases {
    A,
    T,
    G,
    C
};

class Converter
{
    
    std::ifstream input;

    public:
        Converter(std::string const &inputFile);
        void binaryOutput(std::string const &output);
        void humanReadableOutput(std::string const &output);

    private:
        void binaryToHuman(std::ofstream &output, size_t offset); 
        void humanToBinary(std::ofstream &output);
        void processByte(size_t &idx, uint8_t &byte, char &base);
        void finishBinary(size_t amount, std::ofstream &output);
        void setBits(uint8_t &bits, size_t idx, nucleobases base);
        char valueOf(uint8_t bits, size_t idx);
        nucleobases enumVal(char base);
};
        
#endif
