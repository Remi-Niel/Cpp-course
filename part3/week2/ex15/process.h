#ifndef __INCLUDED_PROCESS_H
#define __INCLUDED_PROCESS_H

#include <utility>
#include "abc/abc.h"

class Derived1;
class Derived2;

class Process
{
    ABC &&d_abc;

    public:
        Process(ABC &&abc);
        Process(Derived1 &&abc);
        Process(Derived2 &&abc);

        // template <typename Derived>
        // Process(Derived &&derived);

        void execute();         // calls d_abc.interface()
};

inline Process::Process(ABC &&abc)
:
    d_abc(std::move(abc))
{ }

// template <typename Derived>
// inline Process::Process(Derived &&abc)
// :
//     d_abc(static_cast<ABC&&>(move(abc)))
// { }

inline void Process::execute()
{
    d_abc.interface();
}

#endif