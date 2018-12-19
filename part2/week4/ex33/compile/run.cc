#include "compile.ih"

void Compile::run(std::string const &files)
{
    if (pid() != -1)
        throw "Trying to fork currently forked Compile object.";

    d_files = files;

    fork();
    waitForChild();
}