#include "cpu.ih"

int CPU::dereference(Operand const &value)
{
        // call the appropriate function via pointer (- 1 bc of enum order)
    return (this->*d_deref[static_cast<int>(value.type) - 1])(value.value);
}