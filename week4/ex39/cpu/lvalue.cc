#include "cpu.ih"

bool CPU::lvalue(Operand &op)
{ 	
	//exit incase of read error or lhs cannot be written to
	return !rvalue(op) || op.type == OperandType::VALUE;
}
