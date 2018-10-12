#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <istream>

struct stringsData
{
	std::size_t size;
    std::size_t capacity;
	std::string **strings;
};

class Strings
{
	std::size_t d_size;
    std::size_t d_capacity;
	std::string **d_str;

    public:
    	Strings();
        Strings(int argc, char **argv);
        Strings(char **environ);
        Strings(std::istream &in);
        ~Strings();
        std::size_t size() const;
        std::size_t capacity() const;
        std::string **data() const;
      	void at(std::string &str, std::size_t idx) const;
        void at(char const *&str, std::size_t idx) const;
        void resize(std::size_t count);
        void reserve(std::size_t n = 0);
        stringsData release();

    private:
    	void add(std::string str);
    	void add(char *str);
};

inline size_t Strings::size() const
{
    return d_size;
}

inline size_t Strings::capacity() const
{
    return d_capacity;
}

inline std::string **Strings::data() const
{
    return d_str;
} 
        
#endif
