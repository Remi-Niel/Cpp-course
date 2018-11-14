#ifndef INCLUDED_WRAP_
#define INCLUDED_WRAP_

#include "../data/data.h"

class Wrap
{
    Data::Type d_type;
    Data d_data;

    public:
        Wrap(int argc, char **argv);
        Wrap(char **environ);
        Wrap(std::istream &in);
        Wrap(char const *ntbs);
        Wrap(double value);
        ~Wrap();

        Wrap(Wrap const &copy);
        Wrap(Wrap &&move);
        Wrap &operator=(Wrap const &copy);
        Wrap &operator=(Wrap &&move);

        void swap(Wrap &wrap);

        Data::Type type() const;
        Strings const &words() const;
        std::string const &word() const;
        double value() const;
};

inline Wrap::Wrap(int argc, char **argv)
:   d_type(Data::Type::WORDS), d_data(argc, argv)
{ }

inline Wrap::Wrap(char **environ)
:   d_type(Data::Type::WORDS), d_data(environ)
{ }

inline Wrap::Wrap(std::istream &in)
:   d_type(Data::Type::WORDS), d_data(in)
{ }

inline Wrap::Wrap(char const *ntbs)
:   d_type(Data::Type::WORD), d_data(ntbs)
{ }

inline Wrap::Wrap(double value)
:   d_type(Data::Type::VALUE), d_data(value)
{ }

inline Wrap::Wrap(Wrap const &copy)
:   d_type(copy.d_type), d_data(copy.d_data, d_type)
{ }

inline Wrap::Wrap(Wrap &&move)
:   d_type(move.d_type), d_data(std::move(move.d_data), d_type)
{ }

inline Data::Type Wrap::type() const
{
    return d_type;
}

inline Strings const &Wrap::words() const
{
    return d_data.words();
}

inline std::string const &Wrap::word() const
{
    return d_data.word();
}

inline double Wrap::value() const
{
    return d_data.value();
}


#endif
