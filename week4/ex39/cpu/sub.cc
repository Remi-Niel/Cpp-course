#include "cpu.ih"

void CPU::sub()
{
	Operand op;
	int lhs, rhs;

	if (not twoOperands(op, lhs, rhs))
		return;

	if (op.type == OperandType::MEMORY)
		d_mem.store(op.value, lhs - rhs);
	else
		d_registers[op.value] = lhs - rhs;
}
