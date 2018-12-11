#ifndef INCLUDED_DERIVED_H_
#define INCLUDED_DERIVED_H_

#include <string>
#include "../base/base.h"

class Derived: public Base
{
    std::string const d_line;

    public:
        Derived(std::string str);

    private:
        void v_hello(std::ostream &out) override;
};

inline Derived::Derived(std::string str)
:
    d_line(str)
{}

inline void Derived::v_hello(std::ostream &out)
{
    out << d_line;
}

#endif