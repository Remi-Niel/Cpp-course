#include "arg.ih"

Arg::Arg(char const *opstring, LongOption const *const begin, LongOption const *const end, int argc, char **argv)
{
    d_basename = argv[0];
    longOptions = ArgLongOption();
    shortOptions = ArgOption();
    d_nOptions = 0;

    OptStructArray optStructArray(end - begin);
    OptStruct *opstruct = optStructArray.get();

    for (size_t idx = 0; idx != (size_t) (end - begin); ++idx)
        opstruct[idx] = {begin[idx].d_name, begin[idx].d_type, 0, begin[idx].d_optionChar};

    int option_index = 0;
    int opt = getopt_long(argc, argv, opstring, opstruct, &option_index);
    //Get unprocessed option, untill no such options are left
    while (opt != -1 && opt != ':' && opt != '?')
    {
        if (opt != 0) //short option encountered 
        {
            ++d_nOptions;
            shortOptions.add(opt); 
        }
        else
        {
            ++d_nOptions;
            longOptions.add(opstruct[option_index].name);
        }
        opt = getopt_long(argc, argv, opstring, opstruct, &option_index);
    }

    //Determine if getopt encountered missing or wrong option
    //And exit the program if 1 of these cases occured
    evalGetOpt(opt);

    d_nArgs = argc - optind; //Determine amount of arguments
                             //excluding options

    d_args =new char*[d_nArgs];         //Create array of correct size
    //Add arguments to the array, ommiting options
    for (size_t idx = 0; idx != d_nArgs; ++idx)
        d_args[idx] =  argv[optind + idx];
}
