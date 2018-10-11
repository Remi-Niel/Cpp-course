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
    size_t capacity;
};

class CharCount
{
    CharInfo d_charinfo;

    public:
        CharCount();
        ~CharCount();

        size_t count(std::istream& in);
        size_t capacity() const;
        CharInfo const &info() const;

    private:
        Char *rawCapacity(size_t size);
        void enlarge();
        
        void append(char newchar);
        void insert(char newchar);
        void update(char update);
        int locate(char chin) const;
};

inline CharInfo const &CharCount::info() const
{
    return d_charinfo;
}

inline size_t CharCount::capacity() const
{
    return d_charinfo.capacity;
}

#endif
