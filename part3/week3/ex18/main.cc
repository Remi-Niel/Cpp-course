#include <cstddef>
#include <iostream>

using namespace std;

template<size_t input>
struct NrTrait
{
    enum {
        value = input,
        even = (input + 1) % 2,
        by3 = (input + 1) % 3,
        width = NrTrait<value / 10>::width + 1
    };
};

template<>
struct NrTrait<0>
{
    enum {
        width = 0
    };
};


int main()
{
    cout << NrTrait<1971962>::value << ' ' << NrTrait<1971962>::even << ' ' << 
                NrTrait<1971962>::by3 << ' ' << NrTrait<1971962>::width << '\n';
}