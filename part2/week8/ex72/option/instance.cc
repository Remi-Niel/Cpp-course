#include "option.ih"

Option &Option::instance()
{
    static Option option;
    return option;
}