#include "data.ih"

void Data::swap_value_value(Data &data)
{
    double tmp = u_value;
    u_value = data.u_value;
    data.u_value = tmp;
}