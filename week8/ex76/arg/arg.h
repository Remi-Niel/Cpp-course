#ifndef INCLUDED_ARG_
#define INCLUDED_ARG_

#include <string>
#include <unistd.h>
#include <getopt.h>
#include "../arglongoption/arglongoption.h"
#include "../argoption/argoption.h"

class Arg
{
    static Arg *instance;

    size_t d_nArgs;
    char const* const* d_args; //copy of argv without options

    size_t d_nOptions;
    ArgLongOption longOptions;
    ArgOption shortOptions;


    public:
        enum Type
        {
            None,
            Required,
            Optional
        };

        class LongOption
        {
            char const *d_name;
            Arg::Type d_type;
            int d_optionChar;

            public: 
                LongOption(char const *name, Arg::Type type = Arg::None);
                LongOption(char const *name, int optionChar);
        };

        static Arg &initialize(char const *opstring, int argc, char **argv);
        static Arg &initialize(char const *opstring, LongOption const *const begin, LongOption const *const end, int argc, char **argv);
        static Arg &instance();
        char const *arg(unsigned idx) const;
        std::string const &basename() const;
        size_t nArgs() const;
        size_t nOptions() const;
        size_t option(int opt) const;
        size_t option(std::string const &options) const;
        size_t option(string *value, int option) const;
        size_t option(string *value, char const *longOption) const;
        bool versionHelp(void (*usage)(std::string const *progname), char const *version, size_t minArgs, int helpFlag = 'h', int versionFlag = 'v') const;


    private:    
        Arg();    
};     

#endif
