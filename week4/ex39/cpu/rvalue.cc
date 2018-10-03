#include "cpu.ih"

bool CPU::rvalue(Operand &op)
{
	op.type = tokenizer.token();
	op.value = tokenizer.value();

	switch (op.type)
	{
		OperandType::SYNTAX:
			return error();
		OperandType::REGISTER:
			if (op.value > NREGISTERS)
				return error();
		OperandType::MEMORY:
			if (op.value > RAM::SIZE)
				return error();
	}

	return true;
}
