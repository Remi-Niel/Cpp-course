#include "compile.ih"

#include <iostream>

void Compile::childProcess()
{

    size_t numdefaults = 7;
    string program{ "/usr/bin/g++" };
    string default_arguments[] =
    {
        "/usr/bin/g++",
        "--std=c++2a",
        "-c",
        "/dev/null",
        "-Wall",
        "-Werror",
        "-O2"
    };

    char const *args[numdefaults + d_nfiles + 2];
    
    args[numdefaults + d_nfiles + 1] = nullptr;
    
    //appoint main arguments
    for (size_t idx = 0; idx != 7; ++idx)
        args[idx] = default_arguments[idx].c_str();

    //appoint files
    for (size_t idx = 0; idx != d_nfiles; ++idx)
        args[idx + numdefaults] = d_files[idx].c_str();
    
    int rval = execv(program.c_str(), const_cast<char * const *>(args));

    if (rval == -1)
    {
        cout << "error: " << errno << "\n";
    }
}