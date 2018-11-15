#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <istream>

struct stringsData
{
	std::size_t size;
	std::string *strings;
};

class Strings
{
	std::size_t d_size;
	std::string *d_str;
    public:
    	Strings();
        Strings(int argc, char **argv);
        Strings(char **environ);
        Strings(std::istream &in);
        ~Strings();
        std::size_t size() const;
        std::string *data() const;
        std::string &at(size_t idx);
      	std::string const &at(size_t idx) const;
        stringsData release();
    	void add(std::string const &str);

    private:
        size_t length(char **data) const;
        std::string &at_index(size_t idx) const;
};

inline size_t Strings::size() const
{
    return d_size;
}

inline std::string *Strings::data() const
{
    return d_str;
} 
        
#endif
