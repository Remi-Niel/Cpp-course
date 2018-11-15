#include "cpu.ih"

void CPU::mov()
{
	Operand op;
	int lhs, rhs;

	//exit incase of read error
	if (not twoOperands(op, lhs, rhs))
		return;

	store(op, rhs);
}
