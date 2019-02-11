#ifndef INCLUDED_EXCEPTION_
#define INCLUDED_EXCEPTION_

#include <string>
#include <sstream>
#include <exception>

class Exception: public std::exception
{
    std::string d_what;

    public:
        Exception() = default;

        template<typename T>
        friend Exception &&operator<<(Exception ex, T txt);

        char const *what() const noexcept(true) override;   
};

template<typename T>
Exception &&operator<<(Exception ex, T txt)
{
    std::stringstream ss;
    ss << txt;
    ex.d_what += ss.str();
    return std::move(ex);
}

        
#endif




