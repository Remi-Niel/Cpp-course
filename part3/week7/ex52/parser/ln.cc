#include "parser.ih"

RuleValue &Parser::ln(RuleValue &e)
{
    if (valueOf(e) == 0)
    {
        std::cout << "No power of e can result in 0 \n";
        d_display = false;
        return e = e;
    }

    return e = std::log(valueOf(e));
}
