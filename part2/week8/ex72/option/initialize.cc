#include "option.ih"

void Option::initialize(int argc, char *argv[])
{
    Arg &arg = Arg::initialize(":t:to", long_options, long_end, argc, argv);

    // read arguments.
    string buffer;
    if (arg.option(&buffer, 't'))
        d_nthreads = stoi(buffer);

    if (arg.option(&buffer, 'o'))
        d_output_folder = buffer;
}
