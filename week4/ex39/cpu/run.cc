#include "cpu.ih"

void CPU::run()
{
	while(true)
	{
		Opcode code = tokenizer.opcode(); //Get opcode from tokenizer

		//Call function needed for opcode. If code == STOP break.
		if (instrSwitch(code))
			break;

		tokenizer.reset();	//Prepare tokenizer for next instr
	}
}
