#include "parser.ih"

RuleValue &Parser::sqrt(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "sqrt function expects 1 input variable";
        d_display = false;
        return args[0];
    }
    if (valueOf(args[0]) < 0)
    {
        std::cout << "Sqrt of negative number has no real result\n";
        d_display = false;
        return args[0];
    }

    return args[0] = std::sqrt(valueOf(args[0]));
}
