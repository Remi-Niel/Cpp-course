#include "cpu.ih"

bool CPU::twoOperands(Operand &leftOp, int &lhs, int &rhs)
{
	Operand rightOp;

	//incase of read error return false
	if (not operands(leftOp, rightOp))
		return false;

	lhs = dereference(leftOp);
	rhs = dereference(rightOp);



	return true;

}
