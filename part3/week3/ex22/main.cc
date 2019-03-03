#include <cstddef>
#include <iostream>
#include <tuple>
#include <type_traits>

using namespace std;

template <bool empty, size_t val, size_t base, char... chars>
struct Display
{
    static constexpr char intermediate = (val % base) < 9
        ? '0' + (val % base) 
        : 'a' + (val % base) - 10;

    static constexpr char const *result =
        Display<false, val / base, base, intermediate, chars...>::result;
};

template <size_t base, char ...chars>
struct Display<false, 0, base, chars...>
{
    static constexpr char const result[sizeof...(chars)]{chars...};
};

template <size_t base, char... chars>
struct Display<true, 0, base, chars...>
{
    static constexpr char const result[2]{'0', '\0'};
};

template <size_t val, size_t base>
struct Convert
{
    static constexpr char const *result =
        Display<true, val, base, '\0'>::result;
};

int main()
{
    cout << "     <0, 8>: " << Convert<0, 8>::result << "\n";
    cout << " <57005, 8>: " << Convert<57005, 8>::result << "\n";
    cout << "<57005, 16>: " << Convert<57005, 16>::result << "\n";
    cout << "<57005, 32>: " << Convert<57005, 32>::result << "\n";
}