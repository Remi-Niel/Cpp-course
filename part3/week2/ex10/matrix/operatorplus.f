template <typename Type>
template <typename OtherType>
Matrix<Type> Matrix<Type>::operator+(Matrix<OtherType> const &other)
{
    // cant do this if they aren't of equal size.
    if (!dimensions_match(other))
        throw std::domain_error("Matrix dimensions dont match.");

    Matrix<Type> rval{d_width, d_height};
    for (size_t posx = 0; posx < d_width; ++posx)
    {
        for (size_t posy = 0; posy < d_height; ++posy)
        {
            rval[posx][posy] = static_cast<Type>
            (
                d_data[posx][posy] + other[posx][posy]
            );
        }
    }
    return rval;
}
