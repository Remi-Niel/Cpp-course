#include "parser.ih"

double Parser::acos(std::vector<RuleValue> args)
{   
    if (args.size() != 1)
    {
        std::cout << "acos function expects 1 input variable\n";
        d_display = false;
        return 0.0;
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = std::acos(val);
            val = val / 2 / M_PI * 400;
            break;
        case DEG:
            val = std::acos(val);
            val = val / 2 / M_PI * 360;
            break;
        case RAD:
            val = std::acos(val);
    }
    return val;
}
