#include "tokenizer.ih"

OperandType Tokenizer::parse_operand()
{
    string buffer;
    cin >> buffer; //this format ignores whitespace.

    //If only one char and char within range set value en return 
    // operandtype REGISTER
    if (buffer.size() == 1 && buffer[0] >= 'a' && buffer[0] <= 'z')
    {
        d_value = buffer[0] - 'a';
        return OperandType::REGISTER;
    }

    //If string starts with @ determine int value of the rest of the 
    //string and return OperandType MEMORY
    if (buffer[0] == '@')
    {
        d_value = stoi(buffer.substr(1));
        return OperandType::MEMORY;
    }

    //If string does not only contain numbers return SYNTAX
    if (buffer.find_first_not_of("-1234567890") != string::npos)
        return OperandType::SYNTAX;

    //Convert string to int and return optype VALUE
    d_value = stoi(buffer);
    return OperandType::VALUE;
}