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

    public:
        Data(int argc, char **argv);
        Data(char **environ);
        Data(std::istream &in);
        Data(char const *ntbs);
        Data(double value);

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

        void swap_words_words(Data &data);
        void swap_words_word(Data &data);
        void swap_words_value(Data &data);
        void swap_word_word(Data &data);
        void swap_word_value(Data &data);
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
        
#endif
