#include "cpu.ih"

void CPU::dsp()
{
	Operand op;
	
	if (not rvalue(op))
		return;

	if (op.type == OperandType::MEMORY)
		cout << d_mem.load(op.value) << '\n';
	else if(op.type == OperandType::REGISTER)
		cout << d_registers[op.value] << '\n';
	else
		cout << op.value << '\n';

}
