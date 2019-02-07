#include <iostream>

using namespace std;

template <typename T1>
T1 as(auto in)
{
    return static_cast<T1>(in);
}


int main()
{
    int chVal = 'X';
    cout << as<char>(chVal) << '\n';
}