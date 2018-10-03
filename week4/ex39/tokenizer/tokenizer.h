#ifndef INCLUDED_TOKENIZER_
#define INCLUDED_TOKENIZER_

#include <iostream>
#include <limits>
#include "../enums/enums.h"

class Tokenizer
{
    int d_value; //buffer

    public:

        int value();
        Opcode opcode();
        OperandType token();

        void reset();

    private:
        OperandType parse_operand();
};

inline int Tokenizer::value()
{
    return d_value;
}
        
inline OperandType Tokenizer::token()
{
    return parse_operand();
}

inline void Tokenizer::reset()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

#endif
