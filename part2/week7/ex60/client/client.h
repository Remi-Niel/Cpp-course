#ifndef INCLUDED_CLIENT_
#define INCLUDED_CLIENT_

#include <string>
#include "../storage/storage.h"

class Client
{
    size_t d_size;

    public:
        Client();

        void operator()(Storage &warehouse, std::string filename);
        size_t size() const; 
};

inline Client::Client()
:   d_size(0)
{ }

inline size_t Client::size() const
{
    return d_size;
}
        
#endif
