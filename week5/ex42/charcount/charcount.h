#ifndef INCLUDED_CHARCOUNT_
#define INCLUDED_CHARCOUNT_

#include <istream>
#include <cstddef>

struct Char
{
    char ch;
    size_t count;
};

struct CharInfo
{
    Char* ptr;
    size_t nChar;
};

class CharCount
{
    CharInfo d_charinfo;

    public:
        CharCount();
        ~CharCount();

        size_t count(std::istream& in);
        CharInfo const &info() const;

    private:
        void append(char newchar);
        void insert(char newchar);
        void update(char update);
        int locate(char chin) const;
};

inline CharInfo const &CharCount::info() const
{
    return d_charinfo;
}

#endif
