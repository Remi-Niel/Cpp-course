#include "randbuffer.ih"

RandBuffer::~RandBuffer()
{
    delete[] d_buffer;
}