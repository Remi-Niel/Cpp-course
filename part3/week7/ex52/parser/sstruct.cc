#include "parser.ih"
#include <vector>

RuleValue::RuleValue()
:
    d_type(ANGLESET)
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

RuleValue::RuleValue(double (*func)(std::vector<RuleValue>))
:
    d_type(FUNCTION),
    d_function(func)
{}

