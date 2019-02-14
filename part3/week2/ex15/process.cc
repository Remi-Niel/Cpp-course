#include "process.h"
#include "main.ih"

Process::Process(Derived1 &&abc)
:
    d_abc(static_cast<ABC &&>(move(abc)))
{ }

Process::Process(Derived2 &&abc)
:
    d_abc(static_cast<ABC &&>(move(abc)))
{ }