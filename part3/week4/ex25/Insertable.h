#ifndef INSERTABLE_
#define INSERTABLE_

using namespace std;

template<template <typename> class Policy, typename Data>
struct Insertable: public Policy<Data>
{
    Insertable() = default;
    Insertable(Data in);
    Insertable(Policy<Data>);

    std::ostream &insertInto(std::ostream &out);
};

#endif
