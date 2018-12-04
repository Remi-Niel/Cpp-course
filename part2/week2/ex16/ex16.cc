#include <iostream>
#include <string>

using namespace std;

class ExitLeaks
{
    public:
        ExitLeaks();
        ~ExitLeaks();
};

ExitLeaks::ExitLeaks()
{
    cout << "constructor called!\n";
}

ExitLeaks::~ExitLeaks()
{
    cout << "destructor called!\n";
}

// this function exits, and the object is not destroyed
void leakyFunc()
{
    ExitLeaks leaky{};
    exit(1);
}

// this function throws an exception instead; the object is properly destroyed
void exceptionFunc()
{
    ExitLeaks not_leaky{};
    throw string("exception message goes here\n");
}

int main()
{
    try
    {
        exceptionFunc();
    }
    catch(string str)
    {
        cout << str;
    }
}
