template <typename Type>
void Matrix<Type>::extract(std::istream &in)
{
    for (size_t posy = 0; posy < d_height; ++posy)
    {
        for (size_t posx = 0; posx < d_width; ++posx)
            in >> d_data[posx][posy];
    }
}
