#include "data.ih"

void Data::swap_words_value(Data &data)
{
    double tmp = data.u_value;
    new (&data.u_words) Strings(std::move(u_words));
    destroy_words();
    data.u_value = tmp;
}