#ifndef INCLUDED_BASE_H_
#define INCLUDED_BASE_H_

#include <iostream>

class Base
{
    public:
        void hello(std::ostream &out);
        virtual ~Base();

    private:
        virtual void v_hello(std::ostream &out);
};
#endif