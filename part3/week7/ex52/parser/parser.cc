#include "parser.ih"

Parser::Parser(bool run)
:
    d_constants({
        {"e", M_E},
        {"pi", M_PI}
    }),
    d_functions(),
    d_angle_settings({
        {"rad", RAD},
        {"grad", GRAD},
        {"deg", DEG}
    }),
    d_type(RAD),
    d_display(true)
{
    d_functions.emplace("abs", std::bind(abs,this, std::placeholders::_1, std::placeholders::_2));

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
