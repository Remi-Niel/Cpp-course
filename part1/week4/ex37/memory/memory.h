#ifndef INCLUDED_MEMORY_
#define INCLUDED_MEMORY_

#include "../enums/enums.h"
#include <cstddef>

class Memory
{
	int d_mem[RAM::SIZE];

    
    public:
    	void store(std::size_t address, int value);
    	int load(std::size_t address);
};
        
#endif
