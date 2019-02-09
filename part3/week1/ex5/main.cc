#include <string>

class Operators
    {
        // ...
        public:
            // this is a standard value class. All required 
            // constructors/assignment operators are available

            Operators &operator+=(Operators const &other);
            Operators &operator+=(size_t value);
            Operators &operator+=(std::string const &text);

    };
        
template<typename Type1>
Operators &operator+(Operators &operators, Type1 rhs)
{
    return operators+= rhs;
}

void main()
{
    Operators one;
    Operators two;

    Operators three{ one + two };
    Operators four{ one + 42 };
    Operators four{ one + "hello world" };
}