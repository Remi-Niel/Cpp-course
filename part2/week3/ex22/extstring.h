#include <string>

class ExtString: public std::string
{
    public:
        ExtString(size_t count, std::string const &str);
};

ExtString::ExtString(size_t count, std::string const &str)
{
    for (; count != 0; --count)
        append(str);
}