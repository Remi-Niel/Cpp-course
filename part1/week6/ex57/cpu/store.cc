#include "cpu.ih"

void CPU::store(Operand const &lhs, int value)
{
        // construct array of function pointers (static so only happens once)
    static void (CPU::* const sto[2])(int lhsVal, int val) =
    {
        &CPU::storeReg,
        &CPU::storeMem
    };
        // call appropriate function through pointer in sto[]
    (this->*sto[static_cast<int>(lhs.type) - 2])(lhs.value, value);
}