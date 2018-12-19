#include "main.ih"

#include "compile/compile.h"

int main(int argc, char **argv)
try
{
    Compile compile;

    compile.run("./main.cc");
}
catch (char const *message)
{
    cout << "Exception caught: '" << message << "'\n";
    return -1;
}
