#include "option.ih"

#include <iostream>

namespace
{
    Arg::LongOption long_options[] = 
    {
        Arg::LongOption{"threads", 't'},
        Arg::LongOption{"output", 'o'}
    };
    auto long_end = long_options + std::size(long_options);
}

void Option::initialize(int argc, char *argv[])
{
    Arg &arg = Arg::initialize(":t:o", long_options, long_end, argc, argv);

    // read arguments.
    string buffer;
    if (arg.option(&buffer, 't'))
        d_nthreads = stoi(buffer);

    if (arg.option(&buffer, 'o'))
        d_output_folder = buffer;

    d_input = arg.arg(0);
    cout << "d_input: " << d_input << "\n";
    cout << d_nthreads << "\n";
    cout << d_output_folder << "\n";
}
