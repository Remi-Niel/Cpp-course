#ifndef INCLUDED_ENUMS_
#define INCLUDED_ENUMS_

enum RAM
{
	SIZE = 20
};

enum Opcode
{
	ERR,
	MOV,
	ADD,
	SUB,
	MUL,
	DIV,
	NEG,
	DSP,
	STOP
};

enum OperandType
{
	SYNTAX,
	VALUE,
	REGISTER,
	MEMORY
};

#endif
