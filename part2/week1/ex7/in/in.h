#ifndef INCLUDED_IN_
#define INCLUDED_IN_

#include "../strings/strings.h"

class Strings::In
{
    friend std::ostream &operator<<(std::ostream &out, Strings::In &&in);

    Strings *d_str;
    size_t d_begin;
    size_t d_end;
    char const *d_del;
    void (*d_funPtr)(std::ostream &out, Strings const &str, size_t idx);

    public:
        In(Strings *str, char const *delim);
        In(Strings *str, char const *delim, size_t start);
        In(Strings *str, char const *delim, size_t start, size_t end);
        In(Strings *str, 
            void (*funPtr)(std::ostream &out, 
                            Strings const &str, 
                            size_t idx)
            );
        In(Strings *str, 
            void (*funPtr)(std::ostream &out, 
                        Strings const &str, 
                        size_t idx), 
            size_t start
            );
        In(Strings *str, 
            void (*funPtr)(std::ostream &out, 
                            Strings const &str, 
                            size_t idx), 
            size_t start, 
            size_t end
            );
    private:
        void insertDelim(std::ostream &out, Strings const &str, size_t idx);
        std::ostream &insertInto(std::ostream &out);
};

inline std::ostream &operator<<(std::ostream &out, Strings::In &&in)
{
    return in.insertInto(out);
}
        
#endif
