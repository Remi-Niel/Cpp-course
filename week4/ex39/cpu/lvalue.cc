#include "cpu.ih"

bool CPU::lvalue(Operand &op)
{ 	
	//exit incase of read error or lhs cannot be written to
	if (not rvalue(op) || op.type == OperandType::VALUE)
		return false;

	return true;
}
