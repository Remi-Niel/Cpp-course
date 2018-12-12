#include "fork.ih"

void Fork::fork()
{
    d_pid = ::fork();

    if (d_pid == -1)
        throw "Fork operation failed.";

    if (d_pid == 0)
        childProcess();
    else
        parentProcess();
}