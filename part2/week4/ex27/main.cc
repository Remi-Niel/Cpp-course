#include "main.ih"
#include <iostream>

Base **derivedFactory(size_t size)
{
    Base **set = new Base *[size];

    for (size_t idx = 0; idx != size; ++idx)
        set[idx] = new Derived();

    return set;
}


int main()
{
    Base **bp = derivedFactory(10);

    for (size_t idx = 0; idx != 10; ++idx)
        delete bp[idx];

    delete[] bp;
}