#include <iostream>
#include <string>

using namespace std;

class Demo
{
    string d_name;

    public:
        Demo(string demo_name);
        Demo(Demo const &other);
        void throwCopy();
        inline string const name() const;
};

Demo::Demo(string demo_name)
:
    d_name(demo_name)
{}

Demo::Demo(Demo const &other)
:
    d_name("copy of " + other.d_name)
{}

void Demo::throwCopy()
{
    Demo new_demo("new demo");
    throw new_demo;
}

inline string const Demo::name() const
{
    return d_name;
}

int main()
{
    Demo first_demo("first demo");

    // here a demo object is thrown, then the copy of the copy is caught
    // by an object catcher
    try
    {
        first_demo.throwCopy();
    }
    catch(Demo caught_object)
    {
        cout << "Caught object: " << caught_object.name() << '\n';

        // here we re-throw the caught object, and observe that it is in fact
        // the same object being thrown, not a new copy of that object
        try
        {
            throw;
        }
        catch(Demo recaught_object)
        {
            cout << "Re-caught object: " << caught_object.name() << '\n';
        }
    }

    // here a demo object is thrown, and its copy is caught by the reference
    // catcher, without the need for a second copy to be constructed
    try
    {
        first_demo.throwCopy();
    }
    catch(Demo &caught_reference)
    {
        cout << "Caught reference: " << caught_reference.name() << '\n';
    }
}