#ifndef __matrix_matrix_h
#define __matrix_matrix_h

#include <iostream>
#include <utility> //move
#include <vector>

template <typename Type>
class Matrix
{
    size_t d_width;
    size_t d_height;
    std::vector<std::vector<Type>> d_data;

    public:
        Matrix(size_t width, size_t height);
        Matrix(Matrix const &copy);
        Matrix(Matrix &&move);

        template <size_t W, size_t H>
        Matrix(Type const (&init)[W][H]);

        Matrix &operator=(Matrix const &copy);
        Matrix &operator=(Matrix &&move);

        size_t width() const;
        size_t height() const;
        void swap(Matrix<Type> &swap);

        bool operator==(Matrix const &other);
        bool operator!=(Matrix const &other);

        std::vector<Type> &operator[](size_t index);
        std::vector<Type> const &operator[](size_t index) const;

        template <typename OtherType>
        Matrix operator+(Matrix<OtherType> const &other);
        template <typename OtherType>
        Matrix &operator+=(Matrix<OtherType> const &other);
        
        template <typename OType>
        friend std::ostream &operator<<(std::ostream &out, Matrix<OType> const &mat);
        template <typename IType>
        friend std::istream &operator>>(std::istream &in, Matrix<IType> &mat);

    private:
        template <typename SomeType>
        bool dimensions_match(Matrix<SomeType> const &other);
        
        void extract(std::istream &in);
        void insert(std::ostream &out) const;
};

template <typename Type>
Matrix<Type>::Matrix(size_t width, size_t height)
:
    d_width(width),
    d_height(height)
{
    d_data.resize(d_width, std::vector<Type>(d_height));
}

template <typename Type>
Matrix<Type>::Matrix(Matrix<Type> const &copy)
:
    Matrix(copy.d_width, copy.d_height)
{
    d_data = copy.d_data;
}

template <typename Type>
Matrix<Type>::Matrix(Matrix<Type> &&moved)
:
    d_width(moved.d_width),
    d_height(moved.d_height),
    d_data(std::move(moved.d_data))
{ }

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

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix<Type> const &copy)
{
    Matrix<Type> temp {copy};
    swap(temp);
    return *this;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(Matrix<Type> &&move)
{
    swap(move);
    return *this;
}

template <typename Type>
size_t Matrix<Type>::width() const
{
    return d_width;
}

template<typename Type>
size_t Matrix<Type>::height() const
{
    return d_height;
}

template <typename Type>
void Matrix<Type>::swap(Matrix<Type> &other)
{
    std::swap(d_width, other.d_width);
    std::swap(d_height, other.d_height);
    d_data.swap(other.d_data);
}

template <typename Type>
bool Matrix<Type>::operator==(Matrix<Type> const &other)
{
    return d_data == other.d_data;
}

template <typename Type>
bool Matrix<Type>::operator!=(Matrix<Type> const &other)
{
    // use our own operator so this is always the opposite.
    // even if we change the equal operator.
    return !(*this == other);
}

template <typename Type>
std::vector<Type> &Matrix<Type>::operator[](size_t idx)
{
    return d_data[idx];
}

template <typename Type>
std::vector<Type> const &Matrix<Type>::operator[](size_t idx) const
{
    return d_data[idx];
}

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

template <typename Type>
template <typename SomeType>
bool Matrix<Type>::dimensions_match(Matrix<SomeType> const &other)
{
    if (d_width != other.width())
        return false;
    return d_height == other.height();
}

template <typename Type>
void Matrix<Type>::extract(std::istream &in)
{
    for (size_t posy = 0; posy < d_height; ++posy)
    {
        for (size_t posx = 0; posx < d_width; ++posx)
            in >> d_data[posx][posy];
    }
}

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

template <typename Type>
std::ostream &operator<<(std::ostream &out, Matrix<Type> const &data)
{
    data.insert(out);
    return out;
}

template<typename IType>
std::istream &operator>>(std::istream &in, Matrix<IType> &data)
{
    data.extract(in);
    return in;
}

#endif