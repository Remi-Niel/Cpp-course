#include <string>

std::string *factory(std::string const &str, size_t count)
{
    return new std::string[count]{str};
}