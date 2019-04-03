#include "parser.ih"

double Parser::atan(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "atan function expects 1 input variable\n";
        d_display = false;
        return 0;
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = std::atan(val);
            val = val / 2 / M_PI * 400;
            break;
        case DEG:
            val = std::atan(val);
            val = val / 2 / M_PI * 360;
            break;
        case RAD:
            val = std::atan(val);
    }
    return val;
}
