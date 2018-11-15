#include "cpu.ih"

bool CPU::operands(Operand &lhs, Operand &rhs)
{
	//incase of read error
	if (not (lvalue(lhs) and rvalue(rhs)))
		return false;

	//Only one operand can be of type memory
	if (lhs.type == OperandType::MEMORY and
		rhs.type == OperandType::MEMORY)
		return error();

	return true;
}
