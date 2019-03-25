#include "parser.ih"

RuleValue &Parser::tan(RuleValue &e)
{
    double val = valueOf(e);
    switch (d_type)
    {
        case GRAD:
            val = val * 400 / (2 * M_PI);
            val = std::tan(val);
            val = val * 2 * M_PI / 400;
            break;
        case DEG:
            val = val * 360 / (2 * M_PI);;
            val = std::tan(val);
            val = val * 2 * M_PI / 360;
            break;
        case RAD:
            val = std::tan(val);
    }
    return e = val;
}
