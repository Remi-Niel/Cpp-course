#include "bistreambuffer.ih"

int BiStreamBuffer::overflow(int ch)
{
    d_one << static_cast<char>(ch);
    d_two << static_cast<char>(ch);

    return ch;
}