#ifndef INCLUDED_BISTREAM_
#define INCLUDED_BISTREAM_

#include <ostream>
#include <fstream>
#include "../bistreambuffer/bistreambuffer.h"

class BiStream: private BiStreamBuffer, public std::ostream
{
    public:
        BiStream(std::ostream &one, std::ostream &two);
}; 
        
#endif
