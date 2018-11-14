#include "data.ih"

void Data::swap_word_words(Data &data)
{
    Strings tmp = std::move(data.u_words);
    data.destroy_words();
    data.u_word = std::move(u_word);
    destroy_word();
    u_words = std::move(tmp);
}