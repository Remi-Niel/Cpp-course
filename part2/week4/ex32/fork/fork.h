#ifndef INCLUDED_FORK_
#define INCLUDED_FORK_

#include <sys/types.h>

class Fork
{
    pid_t d_pid = -1;

    public:
        void fork();
        
    protected:
        Fork() = default;
        
        virtual void childProcess();
        virtual void parentProcess();

        Fork(Fork const &copy) = delete; //no copy or move
        Fork &operator=(Fork const &copy) = delete; //no copy or move

        pid_t pid() const;
        int waitForChild() const;
};

#endif
