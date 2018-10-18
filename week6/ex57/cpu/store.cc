#include "cpu.ih"

void CPU::store(Operand const &lhs, int value)
{
        // call appropriate function through pointer in sto[]
    (this->*sto[static_cast<int>(lhs.type) - 2])(lhs.value, value);
}