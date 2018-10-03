#include "cpu.ih"

bool CPU::instrSwitch(Opcode code)
{
	switch(code) //Call relevant function based on opcode
	{
		case Opcode::ERR:
			error();
			break;
		case Opcode::MOV:
			mov();
			break;
		case Opcode::ADD:
			add();
			break;
		case Opcode::SUB:
			sub();
			break;
		case Opcode::MUL:
			mul();
			break;
		case Opcode::DIV:
			div();
			break;
		case Opcode::NEG:
			neg();
			break;
		case Opcode::DSP:
			dsp();
			break;
		case Opcode::STOP:
			return true;
	}

	return false;
}
