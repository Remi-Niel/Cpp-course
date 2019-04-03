#include "parser.ih"

double Parser::tan(std::vector<RuleValue> args)
{
    if (args.size() != 1)
    {
        std::cout << "tan function expects 1 input variable\n";
        d_display = false;
        return 0.0;
    }
    double val = valueOf(args[0]);
    switch (d_type)
    {
        case GRAD:
            val = val / 400 * (2 * M_PI);
            val = std::tan(val);
            break;
        case DEG:
            val = val / 360 * (2 * M_PI);;
            val = std::tan(val);
            break;
        case RAD:
            val = std::tan(val);
    }
    return val;
}
