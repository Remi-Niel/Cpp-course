#include "tokenizer.ih"

static const string opcodes[] = 
{
	"err",
	"mov",
	"add",
	"sub",
	"mul",
	"div",
	"neg",
	"dsp",
	"stop"
};


Opcode Tokenizer::opcode()
{
    string code;
    cin >> code;

    size_t op = -1;
    for (size_t idx = 0; idx < 9; ++idx)
    {
        if (opcodes[idx] == code)
        {
            op = idx;
            break;
        }
    }

    //not found
    if (op == -1) return Opcode::ERR;
    return static_cast<Opcode>(op);
}