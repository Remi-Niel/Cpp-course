#include "cpu.ih"

void CPU::run()
{
    while (execute(d_tokenizer.opcode()))       // eternal loop until done
        d_tokenizer.reset();                    // prepare for the next line
}