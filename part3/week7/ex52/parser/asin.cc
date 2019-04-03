#include "parser.ih"

double Parser::asin(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "asin function expects 1 input variable\n";
        d_display = false;
        return 0.0;
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = std::asin(val);
            val = val / 2 / M_PI * 400;
            break;
        case DEG:
            val = std::asin(val);
            val = val / 2 / M_PI * 360;
            break;
        case RAD:
            val = std::asin(val);
    }
    return val;
}
