#include "cpu.ih"

void CPU::run()
{
	while(true)
	{
		Opcode code = token.opcode(); //Get opcode from tokenizer

		//Call function needed for opcode. If code = STOP break.
		if (instrSwitch(code))
			break;

		token.reset();	//Prepare tokenizer for next instr
	}
}
