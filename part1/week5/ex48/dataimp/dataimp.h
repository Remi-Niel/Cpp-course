#ifndef INCLUDED_DATAIMP_
#define INCLUDED_DATAIMP_

#include <string>

class DataImp
{
    int d_value = 0;
    std::string d_text;

    public:
        bool read();
        void display() const;

};
        
#endif
