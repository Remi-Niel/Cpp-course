#include "arg.ih"

Arg *Arg::s_instance = 0;

Arg &Arg::initialize(char const *opstring, int argc, char **argv)
{
    if (s_instance != 0) //If there already is an instance exit
        throw "Arg already initialized";

    s_instance = new Arg(opstring, argc, argv);
    return *s_instance;

}
