#include "cpu.ih"

void CPU::storeMem(int lhsVal, int val)
{
    d_memory.store(lhsVal, val);
}