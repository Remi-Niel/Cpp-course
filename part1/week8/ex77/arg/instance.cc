#include "arg.ih"

Arg &Arg::instance()
{
    if(!s_instance)
    {
        cerr << "There is no instance\n";
        exit(0);
    }
    return *s_instance;
}
