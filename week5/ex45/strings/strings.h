#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <istream>

class Strings
{
	std::size_t d_size;
	std::string *d_str;
    public:
    	Strings();
        Strings(int argc, char **argv);
        Strings(char **environ);
        Strings(std::istream &in);

    private:
    	void add(std::string str);
    	void add(char *str);
};
        
#endif
