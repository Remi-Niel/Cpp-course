#include "data.ih"

void (Data::*Data::s_swap[][3])(Data &data) = 
{
    {
        &Data::swap_words_words,
        &Data::swap_words_word,
        &Data::swap_words_value
    },
    {
        &Data::swap_word_words,
        &Data::swap_word_word,
        &Data::swap_word_value,
    },
    {
        &Data::swap_value_words,
        &Data::swap_value_word,
        &Data::swap_value_value
    }
};