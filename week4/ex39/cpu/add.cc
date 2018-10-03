#include "cpu.ih"

void CPU::add()
{
	Operand op;
	int lhs, rhs;

	if (not twoOperands(op, lhs, rhs)) //exit incase of read error
		return;

	if (op.type == OperandType::MEMORY)
		d_mem.store(op.value, lhs + rhs);
	else
		d_registers[op.value] = lhs + rhs;
}
