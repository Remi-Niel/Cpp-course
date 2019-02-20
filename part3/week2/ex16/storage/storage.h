#ifndef INCLUDED_STORAGE_
#define INCLUDED_STORAGE_

#include <vector>

template <typename Data>
class Storage
{
    std::vector<Data *> d_data;

    public:
        class iterator : public std::iterator
        <
            std::random_access_iterator_tag,
            Data
        >
        {
            friend Storage<Data>;
            Data **d_item;

            public:
                iterator(iterator const &other) = default;
                iterator &operator=(iterator const &rhv) = default;

                
                iterator &operator++();
                iterator &operator--();
                iterator operator++(int);
                iterator operator--(int);

                bool operator==(iterator const &rhv) const;
                bool operator!=(iterator const &rhv) const;
                bool operator<(iterator const &rhv) const;
                int operator-(iterator const &rhv) const;
                iterator operator+(int step) const;
                iterator operator-(int  step) const;
                Data &operator*();
                Data *operator->();

            private:
                iterator(Data **item);
        };

        typename Storage<Data>::iterator;

        Storage();
        ~Storage();
        std::vector<Data *> &data();

        iterator begin();
        iterator end();
};

template <typename Data>
inline Storage<Data>::Storage()
{ }

template <typename Data>
inline Storage<Data>::~Storage()
{
    for (Data *del : d_data)
        delete del;
}

template <typename Data>
inline std::vector<Data *> &Storage<Data>::data()
{
    return d_data;
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::begin()
{
    return iterator{d_data.data()};
}

template <typename Data>
inline typename Storage<Data>::iterator Storage<Data>::end()
{
    return iterator{d_data.data() + d_data.size()};
}

#include "storageiterator.f"

#endif
