
template<typename T>
struct plus
{
    constexpr T operator()(const T &lhs, const T &rhs) const 
    {
        return lhs + rhs;
    }
};


template <typename Lhs, typename Rhs>
auto operator+(Lhs const &lhs, Rhs const &rhs)
{   
    return Expr<Lhs, Rhs, plus>{ lhs, rhs};
}