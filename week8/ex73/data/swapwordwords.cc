#include "data.ih"

void Data::swap_word_words(Data &data)
{
    Strings tmp = std::move(data.u_words);
    data.destroy_words();
    new (&data.u_word) string(std::move(u_word));
    destroy_word();
    new (&u_words) Strings(std::move(tmp));
}