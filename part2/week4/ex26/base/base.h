#ifndef INCLUDED_BASE_H_
#define INCLUDED_BASE_H_

#include <iostream>

class Base
{
    public:
        virtual ~Base();
        void hello(std::ostream &out);

    private:
        virtual void v_hello(std::ostream &out);
};

inline void Base::hello(std::ostream &out)
{
    v_hello(out);
}

#endif