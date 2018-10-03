#include "cpu.ih"

void CPU::mov()
{
	Operand op;
	int lhs, rhs;

	if (not twoOperands(op, lhs, rhs))
		return;

	if (op.type == OperandType::MEMORY)
		d_mem.store(op.value, rhs);
	else
		d_registers[op.value] = rhs;
}
