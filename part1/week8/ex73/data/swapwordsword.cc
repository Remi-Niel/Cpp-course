#include "data.ih"

void Data::swap_words_word(Data &data)
{
    string tmp = std::move(data.u_word);
    data.destroy_word();
    new (&data.u_words) Strings(u_words);
    destroy_words();
    new (&u_word) string(std::move(tmp));
}