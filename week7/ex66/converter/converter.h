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
        Converter(std::string inputFile);
        void binaryOutput(std::string output);
        void humanReadableOutput(std::string output);

    private:
        void binaryToBinary(std::ofstream &output);
        void binaryToHuman(std::ofstream &output, size_t offset); 
        void humanToBinary(std::ofstream &output);
        void humanToHuman(std::ofstream &output);
        void setBits(uint8_t &bits, size_t idx, nucleobases base);
        char valueOf(uint8_t bits, size_t idx);
        nucleobases enumVal(char base);
};
        
#endif
