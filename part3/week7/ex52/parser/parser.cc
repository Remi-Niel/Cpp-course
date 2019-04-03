#include "parser.ih"

Parser::Parser(bool run)
:
    d_constants({
        {"e", M_E},
        {"pi", M_PI}
    }),
    d_functions({
        {"abs", std::bind(&Parser::abs, this, std::placeholders::_1)},
        {"acos", std::bind(&Parser::acos, this, std::placeholders::_1)},
        {"asin", std::bind(&Parser::asin, this, std::placeholders::_1)},
        {"atan", std::bind(&Parser::atan, this, std::placeholders::_1)},
        {"cos", std::bind(&Parser::cos, this, std::placeholders::_1)},
        {"sin", std::bind(&Parser::sin, this, std::placeholders::_1)},
        {"tan", std::bind(&Parser::tan, this, std::placeholders::_1)},
        {"exp", std::bind(&Parser::exp, this, std::placeholders::_1)},
        {"ln", std::bind(&Parser::ln, this, std::placeholders::_1)},
        {"sqrt", std::bind(&Parser::sqrt, this, std::placeholders::_1)}
    }),
    d_angle_settings({
        {"rad", RAD},
        {"grad", GRAD},
        {"deg", DEG}
    }),
    d_type(RAD),
    d_display(true)
{
    setDebug(false);

    if (run)
        prompt();
    else
    {
        std::cout << "Provide an argument to start the calculator.\n"
                "Use end-of-input (^D) to stop\n";
        throw 1; // ok since we terminate the program
    }    
}
