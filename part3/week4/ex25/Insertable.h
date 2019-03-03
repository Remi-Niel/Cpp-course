#ifndef INSERTABLE_
#define INSERTABLE_
#define HDR_ template<template <typename> class Policy, typename Data>

using namespace std;

HDR_ struct Insertable: public Policy<Data>
{
    template<template <typename> class Policy_shadow, typename Data_shadow>
    friend std::ostream &operator<<(std::ostream &out, Insertable<Policy_shadow, Data_shadow> &data);

    Insertable() = default;
    Insertable(Data in);
    Insertable(Policy<Data>);

    std::ostream &insertInto(std::ostream &out);
};

HDR_ Insertable<Policy, Data>::Insertable(Data in)
    :Policy<Data>({in})
{}

HDR_ Insertable<Policy, Data>::Insertable(Policy<Data> in)
    :Policy<Data>(in)
{}

HDR_ std::ostream &operator<<(std::ostream &out, Insertable<Policy, Data> &data)
{
    return data.insertInto(out);
}

HDR_ std::ostream &Insertable<Policy, Data>::insertInto(ostream &out)
{
    for (Data &s : *this)
    {
        out << s << '\n';
    }

    return out;
}

#undef HDR_
#endif