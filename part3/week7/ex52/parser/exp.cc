#include "parser.ih"

double Parser::exp(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "exp function expects 1 input variable\n";
        d_display = false;
        return 0;
    }
    return std::exp(valueOf(args[0]));
}
