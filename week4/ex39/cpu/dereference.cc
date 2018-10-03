#include "cpu.ih"

int CPU::dereference(Operand op)
{
	switch(op.type)
	{
		case OperandType::VALUE: 	//Get value from operand
			return op.value;
		case OperandType::REGISTER: //get value from register
			return d_registers[op.value];
		case OperandType::MEMORY: 	//Get value from memory
			return d_mem.load(op.value);
		default:					//Cannot occur but prevents warning
			return 0;
	}
}
