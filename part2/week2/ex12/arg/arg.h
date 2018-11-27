#ifndef INCLUDED_ARG_
#define INCLUDED_ARG_

#include <string>
#include <unistd.h>
#include <getopt.h>
#include "../arglongoption/arglongoption.h"
#include "../argoption/argoption.h"
#include "../optstructarray/optstructarray.h"

class Arg
{
    typedef struct option OptStruct; 

    static Arg *s_instance;

    std::string d_basename;

    size_t d_nOptions;

    size_t d_nArgs;
    char **d_args; //copy of argv without options

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
            public:
                char const *d_name;
                Arg::Type d_type;
                int d_optionChar;
             
                LongOption(char const *name, Arg::Type type = Arg::None);
                LongOption(char const *name, int optionChar);
        };

        static Arg &initialize(char const *opstring, int argc, char **argv);
        static Arg &initialize(char const *opstring, LongOption const *const begin, LongOption const *const end, int argc, char **argv);
        static Arg &instance();
        ~Arg();
        char const *arg(unsigned idx) const;
        std::string const &basename() const;
        size_t nArgs() const;
        size_t nOptions() const;
        size_t option(int opt) const;
        size_t option(std::string const &options) const;
        size_t option(std::string *value, int option) const;
        size_t option(std::string *value, char const *longOption) const;
        bool versionHelp(void (*usage)(std::string const *progname), char const *version, size_t minArgs, int helpFlag = 'h', int versionFlag = 'v') const;


    private:    
        Arg(char const *opstring, int argc, char **argv);  
        Arg(char const *opstring, LongOption const *const begin, LongOption const *const end, int argc, char **argv);
        void evalGetOpt(int opt);    //Determine whether getopt encountered problems
};

inline char const *Arg::arg(unsigned idx) const
{
    return d_args[idx];
}

inline std::string const &Arg::basename() const
{
    return d_basename;
}

inline size_t Arg::nArgs() const
{
    return d_nArgs;
}     

inline size_t Arg::nOptions() const
{
    return d_nOptions;
}

inline size_t Arg::option(int opt) const
{
    return shortOptions.size(opt);
}

inline size_t Arg::option(std::string *value, int opt) const
{
    return shortOptions.size(value, opt);
}

inline size_t Arg::option(std::string *value, char const *longOption) const
{
    return longOptions.size(value, longOption);
}

#endif
