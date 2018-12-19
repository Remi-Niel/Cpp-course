#ifndef INCLUDED_COMPILE_
#define INCLUDED_COMPILE_

#include <string>
#include "../fork/fork.h"

class Compile : public Fork
{
    std::string d_files;

    public:
        Compile();

        void run(std::string const &files);
    
    private:
        virtual void childProcess() override;
        virtual void parentProcess() override;
};

inline Compile::Compile()
:
    d_files()
{ }

inline void Compile::parentProcess()
{ }

#endif
