template<typename IType>
std::istream &operator>>(std::istream &in, Matrix<IType> &data)
{
    data.extract(in);
    return in;
}
