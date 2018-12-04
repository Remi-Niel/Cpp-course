#ifndef INCLUDED_BASE_
#define INCLUDED_BASE_

#include <iostream>

class Base
{
    int d_data;

    public:
        Base() = default;
        Base(Base const &other) = default;
        Base(Base &&tmp) = default;
        void printdata();
};

void Base::printdata()
{
    std::cout << "data: " << d_data << '\n';
}

#endif
