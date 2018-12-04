#include <iostream>
#include <string>

using namespace std;

class Demo
{
    string d_name;

    public:
        Demo(string demo_name);
        Demo(Demo const &other);
        void thrower();
        void tellName() const;
};

Demo::Demo(string demo_name)
:
    d_name(demo_name)
{}

Demo::Demo(Demo const &other)
:
    d_name("copy of " + other.d_name)
{}

void Demo::thrower()
{
    throw *this;
}

void Demo::tellName() const
{
    cout << "object name: " << d_name << '\n';
}

int main()
{
    Demo first_demo("first demo");

    // here a demo object is thrown, then the copy of the copy is caught
    // by an object catcher
    try
    {
        first_demo.thrower();       // 'copy of copy of new demo'
    }
    catch(Demo caught_object)
    {
        caught_object.tellName();

        // here we re-throw the caught object, and observe that it is in fact
        // the same object being thrown, not a new copy of that object
        try
        {
            throw;
        }
        catch(Demo recaught_object)
        {
            recaught_object.tellName(); // 'copy of copy of new demo'
        }
    }

    // here a demo object is thrown, and its copy is caught by the reference
    // catcher, without the need for a second copy to be constructed
    try
    {
        first_demo.thrower();
    }
    catch(Demo &caught_reference)
    {
        caught_reference.tellName();    // 'copy of new demo'
    }
}