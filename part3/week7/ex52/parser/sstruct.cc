#include "parser.ih"
#include <vector>

RuleValue::RuleValue()
:
    d_type(ANGLESET),
    d_number(0)
{}

RuleValue::RuleValue(double value)
:
    d_type(VALUE),
    d_number(value)
{}

RuleValue::RuleValue(unsigned idx)
:
    d_type(VARIABLE),
    d_idx(idx)
{}

RuleValue::RuleValue(std::function<double (std::vector<RuleValue>)> func)
:
    d_type(FUNCTION),
    d_function(func)
{}

