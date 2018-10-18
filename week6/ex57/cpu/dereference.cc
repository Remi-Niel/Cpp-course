#include "cpu.ih"

int CPU::dereference(Operand const &value)
{
    switch (value.type)
    {
        default:                    // doesn't happen, but added to avoid
        [[fallthrough]];            // a compiler warning

        case OperandType::VALUE:    // retrieve the various types of values
        return value.value;

        case OperandType::REGISTER:
        return d_register[value.value];

        case OperandType::MEMORY:
        return d_memory.load(value.value);
    }
}