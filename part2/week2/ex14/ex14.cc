#include <iostream>
#include <string>

using namespace std;

class MaxFour
{
    static size_t s_obj_count;

    public:
        MaxFour();
        ~MaxFour();
};

size_t MaxFour::s_obj_count;

MaxFour::MaxFour()
{
    cout << "constructor called...\n";
    ++s_obj_count;

    if (s_obj_count == 4)
        throw string("max. number of objects reached.");
}

MaxFour::~MaxFour()
{
    cout << "destructor called.\n";
}

int main()
{
    MaxFour *mf_array;
    try
    {
        mf_array = new MaxFour[10]();
    }
    catch(string str)
    {
        cout << str << '\n';
    }
}