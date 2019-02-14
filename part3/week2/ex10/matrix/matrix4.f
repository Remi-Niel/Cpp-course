template <typename Type>
template <size_t W, size_t H>
Matrix<Type>::Matrix(Type const (&init)[W][H])
:
    Matrix(W, H)
{
    for (size_t posx = 0; posx < W; ++posx)
    {
        for (size_t posy = 0; posy < H; ++posy)
            d_data[posx][posy] = init[posy][posx];
    }
}