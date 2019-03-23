#include "parser.ih"

RuleValue &Parser::mod(RuleValue &lvalue, RuleValue &rvalue)
{
    //converting to int floors the double, adding 0.5 before flooring makes
    // sure he double is rounded to the nearest integer.
    lvalue.d_number = int(valueOf(lvalue) + 0.5) % int(valueOf(rvalue) + 0.5);
    lvalue.d_type = RuleValue::VALUE;

    return lvalue;
}
