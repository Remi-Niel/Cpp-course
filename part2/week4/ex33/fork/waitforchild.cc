#include "fork.ih"

int Fork::waitForChild() const
{
    int status;
    
    waitpid(d_pid, &status, 0);
    
    return WEXITSTATUS(status);
}