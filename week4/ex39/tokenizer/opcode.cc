#include "tokenizer.ih"

// Opcodes and their base 36 number equivalent
// mov: 29407
// add: 13441
// sub: 37379
// mul: 29613
// div: 17527
// neg: 30328
// dsp: 17881
// stop: 1344841


Opcode Tokenizer::opcode()
{
    string code;
    cin >> code;

    // Convert the command to base 36, see table above for
    // the command equivalents.
    switch(stoul(code, 0, 36))
    {
        case 29407:
            return Opcode::MOV;
        case 13441:
            return Opcode::ADD;
        case 37370:
            return Opcode::SUB;
        case 29613:
            return Opcode::MUL;
        case 17527:
            return Opcode::DIV;
        case 30328:
            return Opcode::NEG;
        case 17881:
            return Opcode::DSP;
        case 1344841:
            return Opcode::STOP;
    }

    return Opcode::ERR;
}