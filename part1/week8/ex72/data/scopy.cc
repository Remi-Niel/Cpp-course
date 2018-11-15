#include "data.ih"

void (Data::*Data::s_copy[])(Data const &data) =
{
    &Data::copy_words,
    &Data::copy_word,
    &Data::copy_value
};