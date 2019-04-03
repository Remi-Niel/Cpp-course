#include "parser.ih"

RuleValue &Parser::cos(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "cos function expects 1 input variable";
        d_display = false;
        return args[0];
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = val * 400 / (2 * M_PI);
            val = std::cos(val);
            val = val * 2 * M_PI / 400;
            break;
        case DEG:
            val = val * 360 / (2 * M_PI);;
            val = std::cos(val);
            val = val * 2 * M_PI / 360;
            break;
        case RAD:
            val = std::cos(val);
    }
    return args[0] = val;
}