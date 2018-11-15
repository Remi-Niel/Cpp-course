#include "data.ih"

void Data::swap_value_word(Data &data)
{
    double tmp = u_value;
    new (&u_word) string(std::move(data.u_word));
    data.destroy_word();
    data.u_value = tmp;
}