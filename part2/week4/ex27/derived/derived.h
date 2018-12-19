#ifndef INCLUDED_DERIVED_H_
#define INCLUDED_DERIVED_H_

#include <string>
#include "../base/base.h"

class Derived: public Base
{
    std::string d_line;

    public:
        Derived();
        Derived(std::string const &str);
        ~Derived() override;

    private:
        void v_hello(std::ostream &out) override;
};
#endif