#include "compile.ih"

void Compile::run(std::string *files, size_t nfiles)
{
    if (pid() != -1)
        throw "Trying to fork already forked Compile object.";

    d_files = files;
    d_nfiles = nfiles;

    fork();

    // pointer is non-owning
    d_files = nullptr;
    d_nfiles = 0;
}