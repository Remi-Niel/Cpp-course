template <typename Type>
std::vector<Type> const &Matrix<Type>::operator[](size_t idx) const
{
    return d_data[idx];
}
