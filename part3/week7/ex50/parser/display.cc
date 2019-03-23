#include "parser.ih"

void Parser::display(RuleValue &e)
{
    if (d_display)
        std::cout << valueOf(e) << "\n";
    prompt();
}
