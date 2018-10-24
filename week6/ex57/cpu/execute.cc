#include "cpu.ih"

bool CPU::execute(Opcode opcode)
{
    if (opcode == Opcode::STOP)
        return false;

        // construct array of function pointers (static so only happens once)
    static void (CPU::* const exec[8])() =
    {
        reinterpret_cast<void (CPU::*)()>(&CPU::error),
        &CPU::mov,
        &CPU::add,
        &CPU::sub,
        &CPU::mul,
        &CPU::div,
        &CPU::neg,
        &CPU::dsp
    };
        // call appropriate function through pointer in exec[]
    (this->*exec[static_cast<int>(opcode)])();
    return true;
}