#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        Arg::LongOption{"debug", Arg::Required},
        Arg::LongOption{"filenames",'f'},
        Arg::LongOption{"help",'h'},
        Arg::LongOption{"version",'v'},
    };
    auto longEnd = longOptions + std::size(longOptions);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize(":df:hv", longOptions, longEnd, argc, argv);

    cout << "n_options: " << arg.nOptions() << ", n_args:" << arg.nArgs() << '\n';

    cout << "f: " << arg.option('f') << '\n';

    cout << "f h: " << arg.option("fh") << '\n';

    string value;
    size_t count = arg.option(&value, 'f');

    cout << "f: " << count << ' ' << value << '\n';

    count = arg.option(&value, "debug");
    cout << "debug: " << count << ' ' << value << '\n';
    
    delete &arg;
}
catch (char const *exception)
{
    cerr << "Exception caught: '" << exception << "'\n";
    return 1;
}
