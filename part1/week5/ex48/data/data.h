#ifndef INCLUDED_DATA_
#define INCLUDED_DATA_

#include <string>

class DataImp;

class Data
{
    DataImp *d_impl;

    public:
        Data();
        ~Data();

        bool read();
        void display() const; 
};
        
#endif
