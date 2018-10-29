#include <iostream>
#include <iomanip>
#include <ctime>


std::ostream &now(std::ostream &stream)
{
        // time(0) returns local time in time_t type
    std::time_t tm {time(0)};   
                                
        // put_time formats and outputs time as specified, in this case (%c)
        // in a form like Sun Oct 17 04:41:13 2010
    return stream << std::put_time(std::localtime(&tm), "%c");
}

int main()
{
    std::cout << now << '\n';
}