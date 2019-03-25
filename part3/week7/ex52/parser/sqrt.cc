#include "parser.ih"

RuleValue &Parser::sqrt(RuleValue &e)
{
    if (valueOf(e) < 0)
    {
        std::cout << "Sqrt of negative number has no real result\n";
        d_display = false;
        return e = e;
    }

    return e = std::sqrt(valueOf(e));
}
