#include "cpu.ih"

bool CPU::execute(Opcode opcode)
{
    switch (opcode)                 // perform the requested action
    {
        case Opcode::ERR:
            error();
        break;         

        case Opcode::MOV:
            mov();
        break;

        case Opcode::ADD:
            add();
        break;

        case Opcode::SUB:
            sub();
        break;

        case Opcode::MUL:
            mul();
        break;

        case Opcode::DIV:
            div();
        break;

        case Opcode::NEG:
            neg();
        break;

        case Opcode::DSP:
            dsp();
        break;

        case Opcode::STOP:      // until all done
        return false;

    } // switch

    return true;                // continue
}