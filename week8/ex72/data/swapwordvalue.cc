#include "data.ih"

void Data::swap_word_value(Data &data)
{
    double tmp = data.u_value;
    data.u_word = std::move(u_word);
    destroy_word();
    data.u_value = tmp;
}