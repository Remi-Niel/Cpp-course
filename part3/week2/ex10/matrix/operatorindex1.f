template <typename Type>
std::vector<Type> &Matrix<Type>::operator[](size_t idx)
{
    return d_data[idx];
}
