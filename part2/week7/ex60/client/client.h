#ifndef INCLUDED_CLIENT_
#define INCLUDED_CLIENT_

#include <string>
#include "../storage/storage.h"

class Client
{
    size_t d_size;

    public:
        void operator()(Storage &warehouse, std::string filename);
        size_t size() const; 
};

inline size_t Client::size() const
{
    return d_size;
}
        
#endif
