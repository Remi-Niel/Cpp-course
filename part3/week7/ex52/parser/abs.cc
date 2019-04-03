#include "parser.ih"

double Parser::abs(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "tan function expects 1 input variable\n";
        d_display = false;
        return 0.0;
    }
    return std::abs(valueOf(args[0]));
}
