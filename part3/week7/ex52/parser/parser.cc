#include "parser.ih"

Parser::Parser(bool run)
:
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
