#include "arg.ih"

void Arg::evalGetOpt(int opt)
{
    switch(opt)
    {
        case ':':
            cerr << "missing at least 1 option\n";
            exit(1);
        case '?':
            cerr << "at least 1 included option not in opstring\n";
            exit(1);
    }
}