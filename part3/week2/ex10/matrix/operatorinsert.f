template <typename Type>
std::ostream &operator<<(std::ostream &out, Matrix<Type> const &data)
{
    data.insert(out);
    return out;
}
