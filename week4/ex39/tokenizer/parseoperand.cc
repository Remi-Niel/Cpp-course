#include "tokenizer.ih"

OperandType Tokenizer::parse_operand()
{
    char c;
    cin >> c; //this format ignores whitespace.

    switch(c)
    {
        case 'a'...'z':
            d_value = c;
            return OperandType::MEMORY;

        case '@':
            cin >> d_value; //read register index.
            return OperandType::REGISTER;
        
        default:
            return OperandType::SYNTAX;
    }
}