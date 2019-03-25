#include "parser.ih"

RuleValue &Parser::asin(RuleValue &e)
{
    double val = valueOf(e);
    switch (d_type)
    {
        case GRAD:
            val = val * 400 / (2 * M_PI);
            val = std::asin(val);
            val = val * 2 * M_PI / 400;
            break;
        case DEG:
            val = val * 360 / (2 * M_PI);;
            val = std::asin(val);
            val = val * 2 * M_PI / 360;
            break;
        case RAD:
            val = std::asin(val);
    }
    return e = val;
}
