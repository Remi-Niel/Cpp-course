template <typename Type>
template <typename SomeType>
bool Matrix<Type>::dimensions_match(Matrix<SomeType> const &other)
{
    if (d_width != other.width())
        return false;
    return d_height == other.height();
}
