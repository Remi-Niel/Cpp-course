#include "storage.h" //for my linter

template <typename Data>
Storage<Data>::iterator::iterator(std::vector<Data *> &container, size_t index)
:
    d_container(container),
    d_index(index)
{ }

template <typename Data>
Storage<Data>::iterator &Storage<Data>::iterator::operator++()
{
    ++d_index;
    return *this;
}

template <typename Data>
Storage<Data>::iterator &Storage<Data>::iterator::operator--()
{
    --d_index;
    return *this;
}

template <typename Data>
Storage<Data>::iterator Storage<Data>::iterator::operator++(int)
{
    auto copy = *this;
    ++d_index;
    return copy;
}

template <typename Data>
Storage<Data>::iterator Storage<Data>::iterator::operator--(int)
{
    auto copy = *this;
    --d_index;
    return copy;
}

template <typename Data>
bool Storage<Data>::iterator::operator==(iterator const &rhv) const
{
    return d_index == rhv.d_index;
}

template <typename Data>
bool Storage<Data>::iterator::operator!=(iterator const &rhv) const
{
    return !(*this == rhv);
}

template <typename Data>
bool Storage<Data>::iterator::operator<(iterator const &rhv) const
{
    return d_index < rhv.d_index;
}

template <typename Data>
int Storage<Data>::iterator::operator-(iterator const &rhv) const
{
    return static_cast<int>(d_index) - static_cast<int>(rhv.d_index);
}

template <typename Data>
Storage<Data>::iterator Storage<Data>::iterator::operator+(int step) const
{
    return iterator{d_index + step};
}

template <typename Data>
Storage<Data>::iterator Storage<Data>::iterator::operator-(int step) const
{
    return iterator{d_index - step};
}

template <typename Data>
Data *&Storage<Data>::iterator::operator*()
{
    return d_container[d_index];
}

template <typename Data>
Data **Storage<Data>::iterator::operator->()
{
    return &d_container[d_index];
}