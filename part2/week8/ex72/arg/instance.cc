#include "arg.ih"

Arg &Arg::instance()
{
    if(!s_instance)
        throw "There is no instance";
    
    return *s_instance;
}
