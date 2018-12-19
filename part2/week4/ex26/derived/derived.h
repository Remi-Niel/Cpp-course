#ifndef INCLUDED_DERIVED_H_
#define INCLUDED_DERIVED_H_

#include <string>
#include "../base/base.h"

class Derived: public Base
{
    std::string d_line;

    public:
        Derived(std::string const &str);

    private:
        void v_hello(std::ostream &out) override;
};

inline Derived::Derived(std::string const &str)
:
    d_line(str)
{}

#endif