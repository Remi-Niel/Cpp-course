#include "data.ih"

void Data::swap_value_words(Data &data)
{
    double tmp = u_value;
    new (&u_words) Strings(std::move(data.u_words));
    data.destroy_words();
    data.u_value = tmp;
}