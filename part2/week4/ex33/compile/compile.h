#ifndef INCLUDED_COMPILE_
#define INCLUDED_COMPILE_

#include <string>
#include "../fork/fork.h"

class Compile : public Fork
{
    size_t d_nfiles;
    std::string *d_files; // Non-owning pointer.

    public:
        Compile();
        virtual ~Compile();

        void run(std::string *files, size_t nfiles);

        virtual void childProcess() override;
        virtual void parentProcess() override;
};

inline Compile::Compile()
:
    d_nfiles(0),
    d_files(nullptr)
{ }

inline void Compile::parentProcess()
{
    throw waitForChild();
}

#endif
