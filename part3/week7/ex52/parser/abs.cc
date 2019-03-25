#include "parser.ih"

RuleValue &Parser::abs(RuleValue &e)
{
    return e = std::abs(valueOf(e));
}
