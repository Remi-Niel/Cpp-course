#include "arg.ih"

Arg::Arg(char const *opstring, int argc, char **argv)
{
    d_basename = argv[0];
    longOptions = ArgLongOption();
    shortOptions = ArgOption();

    int opt = getopt(argc, argv, opstring);
    //Get unprocessed option, untill no such options are left
    while (opt != -1 && opt != ':' && opt != '?')
    {
        shortOptions.add(opt); 
        opt = getopt(argc, argv, opstring);
    }

    //Determine if getopt encountered missing or wrong option
    //And exit the program if 1 of these cases occured
    evalGetOpt(opt);

    d_nOptions = shortOptions.size();

    d_nArgs = argc - optind; //Determine amount of arguments
                             //excluding options

    d_args =new char*[d_nArgs];         //Create array of correct size
    //Add arguments to the array, ommiting options
    for (size_t idx = 0; idx != d_nArgs; ++idx)
        d_args[idx] =  argv[optind + idx];
}
