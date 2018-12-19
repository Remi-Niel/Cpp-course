#include "compile.ih"

#include <iostream>

void Compile::childProcess()
{

    size_t const numdefaults = 7;
    string const default_arguments[] =
    {
        "/usr/bin/g++",
        "--std=c++2a",
        "-c",
        "/dev/null",
        "-Wall",
        "-Werror",
        "-O2"
    };

    char const *args[numdefaults + 2];
    
    args[numdefaults + 1] = nullptr;
    
    //appoint main arguments
    for (size_t idx = 0; idx != 7; ++idx)
        args[idx] = default_arguments[idx].c_str();

    args[numdefaults] = d_files.c_str();
    
    int rval = execv(default_arguments[0].c_str(), const_cast<char * const *>(args));

    if (rval == -1)
    {
        cout << "error: " << errno << "\n";
        throw "Compilation failed!\n";
    }
}