template <typename Type>
bool Matrix<Type>::operator!=(Matrix<Type> const &other)
{
    // use our own operator so this is always the opposite.
    // even if we change the equal operator.
    return !(*this == other);
}
