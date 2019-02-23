#include <cstddef>
#include <iostream>

using namespace std;

template<size_t input>
struct Bin
{
    enum {
        value = Bin<(input >> 1)>::value * 10 + (input & 1)
    };
};

template<>
struct Bin<0>
{
    enum {
        value = 0
    };
};



int main()
{
    cout << Bin<5>::value  << '\n' <<
            Bin<27>::value << '\n';
}