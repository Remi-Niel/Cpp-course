#include "cpu.ih"

bool CPU::rvalue(Operand &op)
{
	op.type = tokenizer.token(); 
	op.value = tokenizer.value();

	switch (op.type)
	{
		case OperandType::SYNTAX:
			return error();
		case OperandType::REGISTER:
			if (op.value > NREGISTERS) //register out of bound
				return error();
		case OperandType::MEMORY:	//memory out of bound
			if (op.value > RAM::SIZE)
				return error();
		default:	//prevents compiler warning
			break;
	}

	return true;
}
