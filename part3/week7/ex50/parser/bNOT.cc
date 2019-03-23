#include "parser.ih"

RuleValue &Parser::bNOT(RuleValue &e)
{
    //converting to int floors the double, adding 0.5 before flooring makes
    // sure he double is rounded to the nearest integer.
    e.d_number = ~ int(valueOf(e) + 0.5);
    e.d_type = RuleValue::VALUE;

    return e;
}
