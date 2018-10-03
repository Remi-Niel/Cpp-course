#ifndef INCLUDED_CPU_
#define INCLUDED_CPU_

#include "../enums/enums.h"
#include "../memory/memory.h"
#include "../tokenizer/tokenizer.h"


enum registers
{
	NREGISTERS = 5
};

struct Operand
{
	OperandType type;
	int value;
};

class CPU
{
	Memory d_mem;
	Tokenizer tokenizer;
	int d_registers[NREGISTERS];

    public:
    	CPU(Memory &mem);
    	void run();
    private:
    	bool instrSwitch(Opcode code);
    	bool error();
    	bool twoOperands(Operand &oper, int &lhs, int &rhs);
    	bool operands(Operand &lhs, Operand &rhs);
    	bool lvalue(Operand &op);
    	bool rvalue(Operand &op);
    	int dereference(Operand op);
    	void mov();
    	void add();
    	void sub();
    	void mul();
    	void div();
    	void neg();
    	void dsp();
};
        
#endif
