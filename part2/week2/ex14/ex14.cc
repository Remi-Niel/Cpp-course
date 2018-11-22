#include <iostream>
#include <string>

using namespace std;

class MaxFour
{
    public:
        static char s_obj_count;
        MaxFour();
        ~MaxFour();
};

char MaxFour::s_obj_count;

MaxFour::MaxFour()
try
{
    s_obj_count++;

    if (s_obj_count == 4)
        throw string("max. number of objects reached.");
}
catch(...)
{
    // any necessary deletion of memory in incomplete object
    throw;
}

MaxFour::~MaxFour()
{
    // any necessary deletion of memory for completed objects
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