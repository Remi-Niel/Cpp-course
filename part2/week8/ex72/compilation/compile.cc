#include "compilation.ih"

#include <iostream>

Result compile(string const &infile)
{
    //const since its used over multiple threads.
    static string const command = "g++ -std=c++17 -Wall -O2 -c ";
    
    // if output specified
    // command += "-o out_location";
    string executer = command + infile;
    string output_file = string{tmpnam(nullptr)};

    string outfolder = Option::instance().output_folder();
    if (outfolder != "")
        executer += "-o " + output_name(infile, outfolder);

    executer += " > " + output_file + " 2>&1";
    
    int exit_code = system(executer.c_str());

    if (exit_code != 0)
        return {false, output_file};
    
    fs::remove(output_file);
    return {true, ""};
}