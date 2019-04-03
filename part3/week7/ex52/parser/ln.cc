#include "parser.ih"

double Parser::ln(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "ln function expects 1 input variable\n";
        d_display = false;
        return 0;
    }
    if (valueOf(args[0]) == 0)
    {
        std::cout << "No power of e can result in 0 \n";
        d_display = false;
        return 0;
    }

    return std::log(valueOf(args[0]));
}
