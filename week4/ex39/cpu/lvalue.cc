#include "cpu.ih"

bool CPU::lvalue(Operand &op)
{

	if (rvalue(op) || op.type == OperandType::VALUE)
		return false;

	return true;
}
