#include "cpu.ih"

void CPU::add()
{
	Operand op;
	int lhs, rhs;

	if (not twoOperands(op, lhs, rhs)) //exit incase of read error
		return;

	store(op, lhs + rhs);
}
