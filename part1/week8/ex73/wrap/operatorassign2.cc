#include "wrap.ih"

Wrap &Wrap::operator=(Wrap &&move)
{
    d_data.move(d_type, std::move(move.d_data), move.d_type);
    d_type = move.d_type;
    return *this;
}