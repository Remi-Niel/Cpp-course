template <typename Type>
void Matrix<Type>::swap(Matrix<Type> &other)
{
    std::swap(d_width, other.d_width);
    std::swap(d_height, other.d_height);
    d_data.swap(other.d_data);
}
