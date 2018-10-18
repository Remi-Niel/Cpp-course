#include "cpu.ih"

void CPU::storeReg(int lhsVal, int val)
{
    d_register[lhsVal] = val;
}