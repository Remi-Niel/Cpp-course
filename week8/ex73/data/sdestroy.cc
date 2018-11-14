#include "data.ih"

void (Data::*Data::s_destroy[])() =
{
    &Data::destroy_words,
    &Data::destroy_word,
    &Data::destroy_value
};