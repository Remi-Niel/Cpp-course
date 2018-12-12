#include "fillingString.h"

std::string FillingString::s_filling = "";

void FillingString::setFilling(std::string str)
{
    s_filling = str;
}

std::string *factory(std::string const &str, size_t count)
{
    FillingString::setFilling(str);
    return new FillingString[count]{};
}