#include "storage.h" //for my linter

// template <typename Data>
// typename Storage<Data>::iterator &Storage<Data>::iterator::operator=(typename Storage<Data>::iterator const &rhv)
// {
//     d_container = rhv.d_container;
//     d_index = rhv.d_index;
//     return *this;
// }

template <typename Data>
Storage<Data>::iterator::iterator(Data **item)
:
    d_item(item)
{ }

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_item;
    return *this;
}

template <typename Data>
typename Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_item;
    return *this;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
    auto copy = *this;
    ++d_item;
    return copy;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
    auto copy = *this;
    --d_item;
    return copy;
}

template <typename Data>
bool Storage<Data>::iterator::operator==(iterator const &rhv) const
{
    return d_item == rhv.d_item;
}

template <typename Data>
bool Storage<Data>::iterator::operator!=(iterator const &rhv) const
{
    return !(*this == rhv);
}

template <typename Data>
bool Storage<Data>::iterator::operator<(iterator const &rhv) const
{
    return d_item < rhv.d_item;
}

template <typename Data>
int Storage<Data>::iterator::operator-(iterator const &rhv) const
{
    return d_item - rhv.d_item;
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator+(int step) const
{
    return iterator{d_item + step};
}

template <typename Data>
typename Storage<Data>::iterator Storage<Data>::iterator::operator-(int step) const
{
    return iterator{d_item - step};
}

template <typename Data>
Data &Storage<Data>::iterator::operator*()
{
    return **d_item;
}

template <typename Data>
Data *Storage<Data>::iterator::operator->()
{
    return d_item;
}