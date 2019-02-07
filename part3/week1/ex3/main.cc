#include <iostream>
#include <string>

using namespace std;

template <typename T>
T* rawCapacity(size_t size)
{
    return new T[size];
}


int main()
{
    size_t length = 10;
    string *strings = rawCapacity<string>(length);

    for (size_t idx = 0; idx != length; ++idx)
        strings[idx] = "test";

    for (size_t idx = 0; idx != length; ++idx)
        cout << strings[idx] << idx << '\n';
}