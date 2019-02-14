#ifndef _INCLUDED_BASE_H
#define _INCLUDED_BASE_H

#include <iostream>

template <typename Derived>
class Base
{
    void insert_into(std::ostream &out) const;

    template<typename ODerived>
    friend std::ostream &operator<<(std::ostream &out, Base<ODerived> const &base);
};

template <typename Derived>
void Base<Derived>::insert_into(std::ostream &out) const
{
    static_cast<Derived const &>(*this).insert_into(out);
}

template <typename ODerived>
std::ostream &operator<<(std::ostream &out, Base<ODerived> const &base)
{
    base.insert_into(out);
    return out;
}

#endif