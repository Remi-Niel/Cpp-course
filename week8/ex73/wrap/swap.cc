#include "wrap.ih"

void Wrap::swap(Wrap &wrap)
{
    Data::Type tmp = wrap.d_type;
    
    d_data.swap(d_type, wrap.d_data, wrap.d_type);
    wrap.d_type = d_type;
    d_type = tmp;
}