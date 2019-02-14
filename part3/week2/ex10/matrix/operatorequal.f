template <typename Type>
bool Matrix<Type>::operator==(Matrix<Type> const &other)
{
    return d_data == other.d_data;
}
