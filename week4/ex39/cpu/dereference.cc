#include "cpu.ih"

int CPU::dereference(Operand op)
{
	switch(op.type)
	{
		case OperandType::VALUE:
			return op.value;
		case OperandType::REGISTER:
			return d_registers[op.value];
		case OperandType::MEMORY:
			return d_mem.load(op.value);
	}
}
