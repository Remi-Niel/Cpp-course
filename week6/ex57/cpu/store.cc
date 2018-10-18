#include "cpu.ih"

void CPU::store(Operand const &lhs, int value)
{
    switch (lhs.type)           // store value in a register or in memory
    {
        default: // not used, but satisfies the compiler
        break;

        case OperandType::REGISTER:
            d_register[lhs.value] = value;
        break;

        case OperandType::MEMORY:
            d_memory.store(lhs.value, value);
        break;
    }
}