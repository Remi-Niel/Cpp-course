#include "cpu.ih"

int CPU::derefReg(int value)
{
    return d_register[value];
}