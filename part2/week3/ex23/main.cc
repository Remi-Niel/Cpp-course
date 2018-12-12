#include <iostream>
#include <string>

using namespace std;

class Base
{
    public:
        void hello();
        virtual ~Base(); //required or dynamic cast wont work.
};

class Derived : public Base
{
    public:
        void hello();
};

void Base::hello()
{
    cout << __PRETTY_FUNCTION__ << ": Hello!\n";
}

Base::~Base()
{
    
}

void Derived::hello()
{
    cout << __PRETTY_FUNCTION__ << ": Hello!\n";
}

void caller(Base &obj)
{
    dynamic_cast<Derived&>(obj).hello();
}

int main()
{
    Derived d;
    caller(d);
}