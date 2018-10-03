#include "cpu.ih"

bool CPU::twoOperands(Operand &leftOp, int &lhs, int &rhs)
{
	Operand rightOp;

	if (not operands(leftOp, rightOp))
		return false;

	lhs = dereference(leftOp);
	rhs = dereference(rightOp);

	return true;

}
