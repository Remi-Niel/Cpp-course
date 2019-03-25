#include "parser.ih"

RuleValue &Parser::exp(RuleValue &e)
{
    return e = std::exp(valueOf(e));
}
