
template<typename Type>
struct plus
{
    constexpr Type operator()(const Type &lhs, const Type &rhs) const 
    {
        return lhs + rhs;
    }
};

template <typename Lhs, typename Rhs>
auto operator+(Lhs const &lhs, Rhs const &rhs)
{   
    return Expr<Lhs, Rhs, plus>{ lhs, rhs};
}