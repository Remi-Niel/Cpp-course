#include "wrap.ih"

Wrap::~Wrap()
{
    d_data.destroy(d_type);
}