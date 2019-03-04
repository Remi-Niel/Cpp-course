#ifndef EXPRESSION_
#define EXPRESSION_
#define HDR_ template <typename Lhs, typename Rhs,\
                                     template <typename> class Operator>

#include <vector>
#include <iostream>
#include <stddef.h>
HDR_ class Expr
{
    template <typename Class>
    struct Trait;

    Lhs const &d_lhs;
    Rhs const &d_rhs;

    public:
        typedef typename Trait<Lhs>::VType VType;
        typedef typename VType::value_type value_type;

        Expr(Lhs const &lhs, Rhs const &rhs);
        operator VType() const;
        auto operator[](size_t idx) const;
        size_t size() const;
};

HDR_ template <typename Class>
struct Expr<Lhs, Rhs, Operator>::Trait
{
    typedef typename Class::VType VType;
};

HDR_ template <typename Type>
struct Expr<Lhs, Rhs, Operator>::Trait<std::vector<Type>>
{
    typedef std::vector<Type> VType;
};


HDR_ size_t Expr<Lhs, Rhs, Operator>::size() const
{
    return d_lhs.size();
}

HDR_ Expr<Lhs,Rhs,Operator>::Expr(Lhs const &lhs, Rhs const &rhs)
:
    d_lhs(lhs),
    d_rhs(rhs)
{}

HDR_ auto Expr<Lhs,Rhs,Operator>::operator[](size_t idx) const
{
    return Operator<value_type>{}(d_lhs[idx], d_rhs[idx]);
}

HDR_ Expr<Lhs,Rhs,Operator>::operator VType() const
{
    VType ret;
    ret.reserve(d_lhs.size());

    for (size_t idx = 0; idx != d_lhs.size(); ++idx)
        new(&ret[idx]) value_type{ (*this)[idx] };

    return ret;
}

template <typename Lhs, typename Rhs>
auto operator+(Lhs const &lhs, Rhs const &rhs)
{   
    return Expr<Lhs, Rhs, std::plus>{ lhs, rhs};
}

template <typename Lhs, typename Rhs>
auto operator*(Lhs const &lhs, Rhs const &rhs)
{   
    return Expr<Lhs, Rhs, std::multiplies>{ lhs, rhs};
}

template <typename Lhs, typename Rhs>
auto operator/(Lhs const &lhs, Rhs const &rhs)
{   
    return Expr<Lhs, Rhs, std::divides>{ lhs, rhs};
}


#undef HDR_
#endif