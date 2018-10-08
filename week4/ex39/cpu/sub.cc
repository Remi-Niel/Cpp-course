#include "cpu.ih"

void CPU::sub()
{
	Operand op;
	int lhs, rhs;

	//exit incase of read error
	if (not twoOperands(op, lhs, rhs))
		return;

	store(op, lhs - rhs);
}
