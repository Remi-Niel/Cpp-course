#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include <string>
#include <iosfwd>

#include "../strings/strings.h"



union Data
{
    enum Type
    {
        WORDS,
        WORD,
        VALUE
    };

    private:
        Strings u_words;
        std::string u_word;
        double u_value;

        static void (Data::*s_copy[])(Data const &data);
        static void (Data::*s_destroy[])();
        static void (Data::*s_swap[][3])(Data &data);

    public:
        Data(int argc, char **argv);
        Data(char **environ);
        Data(std::istream &in);
        Data(char const *ntbs);
        Data(double value);
        ~Data();

        Data(Data const &data, Type type);
        Data(Data &&data, Type type);

        Data &copy(Type current, Data const &other, Type next);
        Data &move(Type current, Data &&other, Type next);
        void swap(Type current, Data &other, Type next);
        void destroy(Type type);

    private:
        void destroy_words();
        void destroy_word();
        void destroy_value(); // for completeness.
        
        void copy_words(Data const &data);
        void copy_word(Data const &data);
        void copy_value(Data const &data);

        void swap_words_words(Data &data); // X
        void swap_words_word(Data &data); // X
        void swap_words_value(Data &data); // X
        void swap_word_words(Data &data); // X
        void swap_word_word(Data &data); // X
        void swap_word_value(Data &data); // X
        void swap_value_words(Data &data);
        void swap_value_word(Data &data);
        void swap_value_value(Data &data);
};

inline Data::Data(int argc, char **argv)
:   u_words(argc, argv)
{ }

inline Data::Data(char **environ)
:   u_words(environ)
{ }

inline Data::Data(std::istream &in)
:   u_words(in)
{ }

inline Data::Data(char const *ntbs)
:   u_word(ntbs)
{ }

inline Data::Data(double value)
:   u_value(value)
{ }

inline Data::Data(Data const &data, Type type)
{
    (this->*s_copy[type])(data);
}

inline Data::Data(Data &&data, Type type)
{
    move(VALUE, std::move(data), type);
}

inline void Data::swap(Type current, Data &other, Type next)
{
    (this->*s_swap[current][next])(other);
}

inline void Data::destroy(Type type)
{
    (this->*s_destroy[type])();
}

inline void Data::destroy_words()
{
    u_words.~Strings();
}

inline void Data::destroy_word()
{
    u_word.~basic_string();
}

inline void Data::destroy_value()
{
    //nothing needs to happen here
}

inline void Data::copy_words(Data const &data)
{
    u_words = data.u_words;
}

inline void Data::copy_word(Data const &data)
{
    u_word = data.u_word;
}

inline void Data::copy_value(Data const &data)
{
    u_value = data.u_value;
}

inline void Data::swap_words_words(Data &data)
{
    u_words.swap(data.u_words);
}

inline void Data::swap_word_word(Data &data)
{
    u_word.swap(data.u_word);
}

#endif
