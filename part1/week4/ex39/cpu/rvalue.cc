#include "cpu.ih"

bool CPU::rvalue(Operand &op)
{
	op.type = d_tokenizer.token(); 
	op.value = d_tokenizer.value();

	switch (op.type)
	{
		case OperandType::SYNTAX:
			return error();
		break;
		case OperandType::REGISTER:
			if (op.value > NREGISTERS) //register out of bound
				return error();
		break;
		case OperandType::MEMORY:	//memory out of bound
			if (op.value > RAM::SIZE)
				return error();
		break;
		default:	//prevents compiler warning
			break;
	}

	return true;
}
