#include <cstddef>
#include <iostream>

using namespace std;


template<size_t input>
struct Width_helper
{
    enum {
        value = Width_helper<input / 10>::value + 1
    };
};

template<>
struct Width_helper<0>
{
    enum {
        value = 0
    };
};

//Needed for case input = 0
// otherwise width would become 0 for input = 0
template<size_t input>
struct Width
{
    enum {
        value = Width_helper<input / 10>::value + 1
    };
};

template<size_t input>
struct NrTrait
{
    enum {
        value = input,
        even = (input + 1) % 2,
        by3 = (input + 1) % 3,
        width = Width<input>::value
    };
};


int main()
{
    cout << NrTrait<1971962>::value << ' ' << NrTrait<1971962>::even << ' ' << 
                NrTrait<1971962>::by3 << ' ' << NrTrait<1971962>::width << '\n';
}