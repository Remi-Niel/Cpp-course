#include "cpu.ih"

int CPU::dereference(Operand const &value)
{
        // construct array of function pointers (static so only happens once)
    static int (CPU::* const deref[3])(int value) =
    {
        &CPU::derefVal,
        &CPU::derefReg,
        &CPU::derefMem
    };
        // call the appropriate function via pointer (- 1 bc of enum order)
    return (this->*deref[static_cast<int>(value.type) - 1])(value.value);
}