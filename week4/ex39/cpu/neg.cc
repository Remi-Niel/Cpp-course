#include "cpu.ih"

void CPU::neg()
{
	Operand op;
	
	//exit incase of read error
	if (not rvalue(op))
		return;

	if (op.type == OperandType::MEMORY)
		d_mem.store(op.value, -d_mem.load(op.value));
	else if(op.type == OperandType::REGISTER)
		d_registers[op.value] = -d_registers[op.value];

}
