#include "arg.ih"

void Arg::evalGetOpt(int opt)
{
    switch(opt)
    {
        case ':':
            throw "missing at least 1 option";
            
        case '?':
            throw "at least 1 included option not in opstring";
    }
}