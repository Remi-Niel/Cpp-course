template <typename Type>
void Matrix<Type>::insert(std::ostream &out) const
{
    out << "[\n";
    for (size_t posy = 0; posy < d_height; ++posy)
    {
        out << "    [";
        for (size_t posx = 0; posx < d_width; ++posx)
            out << d_data[posx][posy] << ',';
        out << "],\n";
    }
    out << ']';
}
