#ifndef _INCLUDED_RULEVALUE_H_
#define _INCLUDED_RULEVALUE_H_

#include <vector>
#include <functional>
struct RuleValue
{
    enum Type
    {
        VALUE,
        VARIABLE,
        LIST,
        FUNCTION,
        ANGLESET
    };

    Type                    d_type;
    double                  d_number;
    unsigned                d_idx;
    std::vector<RuleValue>  d_argList;
    std::function<double (std::vector<RuleValue>)> d_function;

    public:
        RuleValue();
        RuleValue(double value);
        RuleValue(unsigned idx);
        RuleValue(std::function<double (std::vector<RuleValue>)> fun);
};

#endif
