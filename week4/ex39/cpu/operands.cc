#include "cpu.ih"

bool CPU::operands(Operand &lhs, Operand &rhs)
{
	if (!lvalue(lhs) || !lvalue(rhs))
		return false;

	if (lhs.type == OperandType::MEMORY and
		rhs.type == OperandType::MEMORY)
		return error();

	return true;
}
