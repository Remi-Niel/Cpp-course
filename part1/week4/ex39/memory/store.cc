#include "memory.ih"

void Memory::store(size_t address, int value)
{
	if (address < RAM::SIZE)
		d_mem[address] = value;
}
