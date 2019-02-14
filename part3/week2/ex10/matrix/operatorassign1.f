template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix<Type> const &copy)
{
    Matrix<Type> temp {copy};
    swap(temp);
    return *this;
}
