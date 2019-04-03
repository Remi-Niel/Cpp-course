#include "parser.ih"

double Parser::sin(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "sin function expects 1 input variable\n";
        d_display = false;
        return 0;
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = val / 400 * 2 * M_PI;
            val = std::sin(val);
            break;
        case DEG:
            val = val / 360 * 2 * M_PI;
            val = std::sin(val);
            break;
        case RAD:
            val = std::sin(val);
    }
    return val;
}
