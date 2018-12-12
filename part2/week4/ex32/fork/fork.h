#ifndef INCLUDED_FORK_
#define INCLUDED_FORK_

#include <sys/types.h>

class Fork
{
    pid_t d_pid = 0;

    public:
        void fork();
        
        virtual void childProcess() = 0;
        virtual void parentProcess() = 0;
    
    protected:
        Fork() = default;
        virtual ~Fork();

        Fork(Fork const& copy) = delete; //no copy or move
        Fork &operator=(Fork const& copy) = delete; //no copy or move

        pid_t pid() const;
        int waitForChild() const;
};
        
#endif
