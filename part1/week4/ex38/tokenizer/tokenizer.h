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

        bool is_register(std::string const &str);
        bool is_memory(std::string const &str);
        bool is_syntax(std::string const &str);
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
