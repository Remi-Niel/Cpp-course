#include "data.ih"

void Data::swap_words_word(Data &data)
{
    Strings tmp = std::move(data.u_words);
    data.u_words = std::move(u_words);
    u_words.swap(tmp);
}