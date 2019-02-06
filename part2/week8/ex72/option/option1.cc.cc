#include "option.ih"

Option::Option()
:   d_nthreads(thread::hardware_concurrency()),
    d_output_folder("")
{ }