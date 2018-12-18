#include "vectorwrapper.ih"

void VectorWrapper::swap(VectorWrapper &other)
{
    char buffer[sizeof(VectorWrapper)];
    memcpy(buffer, this,   sizeof(VectorWrapper));
    memcpy(this,   &other, sizeof(VectorWrapper));
    memcpy(&other, buffer, sizeof(VectorWrapper));
}
