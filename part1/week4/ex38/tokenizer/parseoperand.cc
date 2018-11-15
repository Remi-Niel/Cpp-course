#include "tokenizer.ih"

OperandType Tokenizer::parse_operand()
{
    string buffer;
    cin >> buffer; //this format ignores whitespace.

    //If only one char and char within range set value en return 
    // operandtype REGISTER
    if (is_register(buffer))
        return OperandType::REGISTER;

    //If string starts with @ determine int value of the rest of the 
    //string and return OperandType MEMORY
    if (is_memory(buffer))
        return OperandType::MEMORY;

    //If string does not only contain numbers return SYNTAX
    if (is_syntax(buffer))
        return OperandType::SYNTAX;

    //Convert string to int and return optype VALUE
    d_value = stoi(buffer);
    return OperandType::VALUE;
}