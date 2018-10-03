#include "memory.ih"

int Memory::load(size_t address)
{
	if (address < RAM::SIZE)
		return d_mem[address];
	
	return 0;
}
