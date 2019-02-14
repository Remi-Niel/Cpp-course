template <typename Type>
Matrix<Type>::Matrix(Matrix<Type> const &copy)
:
    Matrix(copy.d_width, copy.d_height)
{
    d_data = copy.d_data;
}
