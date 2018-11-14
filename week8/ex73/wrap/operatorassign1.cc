#include "wrap.ih"

Wrap &Wrap::operator=(Wrap const &copy)
{
    d_data.destroy(d_type);
    d_data.copy(d_type, copy.d_data, copy.d_type);
    d_type = copy.d_type;
    return *this;
}