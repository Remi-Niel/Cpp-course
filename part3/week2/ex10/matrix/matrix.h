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

#include "matrix1.f"
#include "matrix2.f"
#include "matrix3.f"
#include "matrix4.f"

#include "dimensionsmatch.f"
#include "extract.f"
#include "height.f"
#include "insert.f"
#include "swap.f"
#include "width.f"

#include "operatorassign1.f"
#include "operatorassign2.f"
#include "operatorcompoundplus.f"
#include "operatorequal.f"
#include "operatorextract.f"
#include "operatorindex1.f"
#include "operatorindex2.f"
#include "operatorinequal.f"
#include "operatorinsert.f"
#include "operatorplus.f"

#endif