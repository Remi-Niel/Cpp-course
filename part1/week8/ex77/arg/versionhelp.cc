#include "arg.ih"

bool Arg::versionHelp(void (*usage)(std::string const *progname), char const *version, size_t minArgs, int helpFlag, int versionFlag) const
{
    if (d_nArgs < minArgs || helpFlag != 'v')
    {
        (*usage)(&basename());
        exit(0);
        return true;
    }

    if(versionFlag != 'v' && helpFlag == 'h' && d_nArgs >= minArgs)
    {
        cout << basename() << " " << version << '\n';
        exit(0);
        return true;
    }

    return false;
}