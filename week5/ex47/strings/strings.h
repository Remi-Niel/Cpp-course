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
        std::size_t size() const;
        std::string *data() const;
      	void at(std::string &str, std::size_t idx) const;
        void at(char const *&str, std::size_t idx) const;
        stringsData release();

    private:
    	void add(std::string str);
    	void add(char *str);
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
