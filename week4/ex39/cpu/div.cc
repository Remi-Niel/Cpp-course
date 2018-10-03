#include "cpu.ih"

void CPU::div()
{
	Operand op;
	int lhs, rhs;

	if (not twoOperands(op, lhs, rhs) || rhs == 0)
		return; 	//exit incase of read error or division by 0

	if (op.type == OperandType::MEMORY)
		d_mem.store(op.value, lhs / rhs);
	else
		d_registers[op.value] = lhs / rhs;
}
