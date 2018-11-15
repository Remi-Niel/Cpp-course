#include "cpu.ih"

void CPU::run()
{
	while(true)
	{
		Opcode code = d_tokenizer.opcode(); //Get opcode from tokenizer

		//Call function needed for opcode. If code == STOP break.
		if (instrSwitch(code))
			break;

		d_tokenizer.reset();	//Prepare tokenizer for next instr
	}
}
