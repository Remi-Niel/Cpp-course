#ifndef INCLUDED_BASE_H_
#define INCLUDED_BASE_H_

#include <iostream>

class Base
{
    public:
        void hello(std::ostream &out);

    private:
        virtual void v_hello(std::ostream &out);
};

inline void Base::hello(std::ostream &out)
{
    v_hello(out);
}

inline void Base::v_hello(std::ostream &out)
{
    out << "hello from Base\n";
}

#endif