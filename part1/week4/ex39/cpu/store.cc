#include "cpu.ih"

void CPU::store(Operand op, int val)
{
    if(op.type == OperandType::MEMORY)
        d_mem.store(op.value, val);
    else
        d_registers[op.value] = val;
}