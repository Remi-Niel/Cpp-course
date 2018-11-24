#include <iostream>
#include <string>

using namespace std;

class ExitLeaks
{
    string **sentences;

    public:
        ExitLeaks();
        ~ExitLeaks();
        void fun();
};

ExitLeaks::ExitLeaks()
{
    cout << "constructor called!\n";
    sentences = new string *[20];
    for (size_t idx = 0; idx != 20; ++idx)
    {
        sentences[idx] = new string[20];
    }
}

ExitLeaks::~ExitLeaks()
{
    cout << "destructor called!\n";
    for (size_t idx = 0; idx != 20; ++idx)
    {
        delete[] sentences[idx];
    }
    delete[] sentences;
}

// useless function to ensure object is not removed as unused
void ExitLeaks::fun()
{
    cout << "...\n";
}

// this function exits, and the object is not destroyed
void leakyFunc()
{
    ExitLeaks lil_leaky{};
    lil_leaky.fun();
    exit(1);
}

int main()
{
    leakyFunc();
}