#include "parser.ih"

RuleValue &Parser::exp(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "tan function expects 1 input variable";
        d_display = false;
        return args[0];
    }
    return args[0] = std::exp(valueOf(args[0]));
}
