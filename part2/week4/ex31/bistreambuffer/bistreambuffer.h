#ifndef INCLUDED_BISTREAMBUFFER_
#define INCLUDED_BISTREAMBUFFER_

#include <streambuf>

class BiStreamBuffer: public std::streambuf
{
    std::ostream &d_one;
    std::ostream &d_two;
    public:
        BiStreamBuffer(std::ostream &one, std::ostream &two);
        
    private:
        int overflow(int ch) override;
};
        
#endif
