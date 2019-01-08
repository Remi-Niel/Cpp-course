#include "vectorwrapper.ih"

void VectorWrapper::swap(VectorWrapper &other)
{
    other.d_strings.swap(d_strings);
}
