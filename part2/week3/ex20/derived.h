#ifndef INCLUDED_DERIVED_
#define INCLUDED_DERIVED_

class Derived: public Base
{

    public:
        Derived() 
        : Base() 
        {}

        Derived(Derived const &other) 
        : Base(other)
        {}

        Derived(Derived &&tmp) 
        : Base(std::move(tmp))
        {}
};
        
#endif
