template <typename Type>
Matrix<Type>::Matrix(Matrix<Type> &&moved)
:
    d_width(moved.d_width),
    d_height(moved.d_height),
    d_data(std::move(moved.d_data))
{ }
