#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <memory>
#include <iostream>

class Data
{
    typedef std::vector<std::shared_ptr<std::string>> DataVector;

    DataVector d_data;

    public:
        typedef std::string value_type;
        void push_back(std::string str);
};

inline void Data::push_back(std::string str)
{
    d_data.push_back(std::make_shared<std::string>(str));
    std::cout << str << '\n';
}


#endif