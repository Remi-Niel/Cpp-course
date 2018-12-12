#ifndef INCLUDED_BISTREAMBUFFER_
#define INCLUDED_BISTREAMBUFFER_

#include <streambuf>
#include <string>

class BiStreamBuffer: public std::streambuf
{
    std::streambuf *d_one;
    std::streambuf *d_two;
    public:
        BiStreamBuffer(std::streambuf *one, std::streambuf *two);
        ~BiStreamBuffer() override;

    private:
        std::streamsize xsputn( const char_type* s, std::streamsize count ) override;
};
        
#endif
