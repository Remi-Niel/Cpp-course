#ifndef INCLUDED_CPU_
#define INCLUDED_CPU_

#include "../enums/enums.h"
#include "../memory/memory.h"


enum registers
{
	NREGISTERS = 5
};

class CPU
{
	Memory d_mem;
	Tokenizer token;
	int d_registers[NREGISTERS];

    public:
    	CPU(Memory &mem);
    	void run();
    private:
    	bool instrSwitch(Opcode code);
    	bool error();
    	void mov();
    	void add();
    	void sub();
    	void mul();
    	void div();
    	void neg();
    	void dsp();
};

inline CPU::CPU(Memory &mem)
{
	d_mem = mem;
}
        
#endif
