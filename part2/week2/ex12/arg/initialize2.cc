#include "arg.ih"

Arg &Arg::initialize(char const *opstring, LongOption const *const begin, LongOption const *const end, int argc, char **argv)
{
    if (s_instance != 0) //If there already is an instance exit
        throw "Arg already initialized";

    s_instance = new Arg(opstring, begin, end, argc, argv);
    return *s_instance;

}
