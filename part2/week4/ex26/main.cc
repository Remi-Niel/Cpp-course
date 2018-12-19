#include "main.ih"

int main()
{
    Base base{};
    Derived derived{"hello from derived\n"};

    Message message1{base};
    Message message2{derived};

    message1.show(std::cout);
    message2.show(std::cout);
}