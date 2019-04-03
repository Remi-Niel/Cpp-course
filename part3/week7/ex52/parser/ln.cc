#include "parser.ih"

RuleValue &Parser::ln(std::vector<RuleValue> args)
{
    if (valueOf(args[0]) == 0)
    {
        std::cout << "No power of e can result in 0 \n";
        d_display = false;
        return args[0];
    }

    return args[0] = std::log(valueOf(args[0]));
}
