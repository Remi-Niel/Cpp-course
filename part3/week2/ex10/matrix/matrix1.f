template <typename Type>
Matrix<Type>::Matrix(size_t width, size_t height)
:
    d_width(width),
    d_height(height)
{
    d_data.resize(d_width, std::vector<Type>(d_height));
}