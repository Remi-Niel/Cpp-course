template <typename Type>
template <typename OtherType>
Matrix<Type> &Matrix<Type>::operator+=(Matrix<OtherType> const &other)
{
    if (!dimensions_match(other))
        throw std::domain_error("Matrix dimensions dont match.");

    for (size_t posx = 0; posx < d_width; ++posx)
    {
        for (size_t posy = 0; posy < d_height; ++posy)
            d_data[posx][posy] += other[posx][posy];
    }
    return *this;
}
