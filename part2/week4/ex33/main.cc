#include "main.ih"

#include "compile/compile.h"

int main(int argc, char **argv)
try
{
    Compile compile;

    string files[] = 
    {
        "./main.cc"
    };

    compile.run(files, 1);
}
catch (int exitcode)
{
    return exitcode;
}
