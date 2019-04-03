#ifndef _INCLUDED_RULEVALUE_H_
#define _INCLUDED_RULEVALUE_H_

#include <vector>

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
    RuleValue &(*d_function)(std::vector<RuleValue>);

    public:
        RuleValue();
        RuleValue(double value);
        RuleValue(unsigned idx);
        RuleValue(double (*func)(std::vector<RuleValue>));
};

#endif
