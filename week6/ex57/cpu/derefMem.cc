#include "cpu.ih"

int CPU::derefMem(int value)
{
    return d_memory.load(value);
}