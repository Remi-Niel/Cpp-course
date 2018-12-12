#include "bistreambuffer.ih"

std::streamsize BiStreamBuffer::xsputn( const char_type* s, std::streamsize count )
{
    d_one->sputn(s, count);
    return d_two->sputn(s, count); 
}
