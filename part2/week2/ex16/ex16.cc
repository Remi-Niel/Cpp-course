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

// this function throws an exception, and the local object is destroyed
void wellBehavedFunc()
{
    ExitLeaks well_behaved{};
    well_behaved.fun();
    throw string("something terrible happened! (but it's handled well)\n");
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
    cout << "[1] Well-behaved Function\n[2] Leaky Function\n> ";
    int choice;
    cin >> choice;

    // well behaved function is called from within a try block, after the
    // exception is thrown the destructor of the local object is called
    if (choice == 1)
    {
        try
        {
            wellBehavedFunc();
        }
        catch (string str)
        {
            cout << str;
            return 1;
        }
    }
    
    if (choice == 2)
        leakyFunc();
}
