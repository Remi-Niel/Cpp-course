#include <iostream>

using namespace std;

template <typename T1, typename T2>
inline T1 as(T2 const &in)
{
    return static_cast<T1>(in);
}


int main()
{
    int chVal = 'X';
    cout << as<char>(chVal) << '\n';
}