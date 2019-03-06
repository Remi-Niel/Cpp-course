#ifndef __INCLUDED_PTR_H
#define __INCLUDED_PTR_H

#include <functional>
#include <type_traits>



template <typename Type>
class Ptr
{
    Type *d_pointer;
    std::function<void()> d_deleter;

    public:
        template <typename AType>
        Ptr(AType *pointer);

        ~Ptr();

        template <typename AType>
        void reset(AType *pointer);
};

template <typename Type>
template <typename AType>
inline Ptr<Type>::Ptr(AType *pointer)
{
    static_assert(std::is_base_of<Type, AType>::value, "Argument type not same or derived from Ptr type");
    d_pointer = pointer;
    d_deleter = [=]()
    {
        delete pointer;
    };
}

template <typename Type>
inline Ptr<Type>::~Ptr()
{
    d_deleter();
}

template <typename Type>
template <typename AType>
inline void Ptr<Type>::reset(AType *pointer)
{
    static_assert(std::is_base_of<Type, AType>::value, "Argument type not same or derived from Ptr type");
    d_deleter();

    d_pointer = pointer;
    d_deleter = [=]()
    {
        delete pointer;
    };
}

#endif