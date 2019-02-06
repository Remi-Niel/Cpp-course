#pragma once

#include "../arg/arg.h"

namespace
{
    Arg::LongOption long_options[] = 
    {
        Arg::LongOption{"threads", 't'},
        Arg::LongOption{"output", 'o'}
    };
    auto long_end = long_options + std::size(long_options);
}

class Option
{
    size_t d_nthreads;
    std::string d_output_folder;

    public:
        static Option &instance();

        void initialize(int argc, char *argv[]);

        size_t nthreads() const;
        std::string const &output_folder() const;

    private:
        Option();

        Option(Option const &copy) = delete;
        Option &operator=(Option const &copy) = delete;
};

inline size_t Option::nthreads() const
{
    return d_nthreads;
}

inline std::string const &Option::output_folder() const
{
    return d_output_folder;
}

