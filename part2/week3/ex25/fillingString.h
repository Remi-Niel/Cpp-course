#include <string>

class FillingString: public std::string
{
    static std::string s_filling;

    public:
        FillingString();
        static void setFilling(std::string str);
};

FillingString::FillingString()
:
    std::string{s_filling}
{}