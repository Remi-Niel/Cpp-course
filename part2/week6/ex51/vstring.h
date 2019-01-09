#ifndef VSTRING_H
#define VSTRING_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

class Vstring: public std::vector<std::string>
{
    public:
        typedef std::map<char, size_t> CharMap;

        Vstring(std::istream &in);

        size_t count(CharMap &cmap, bool (*accept)(char, CharMap &));

    private:
        static size_t countChar(std::string const &str, CharMap &cmap, 
                                bool (*accept)(char, CharMap &));
};

#endif