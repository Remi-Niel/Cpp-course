#include <cstddef>
#include <iostream>
#include <tuple>
#include <type_traits>

using namespace std;

template <bool empty, size_t val, size_t base, char... chars>
struct Display
{
    static constexpr char const *result = Display<false, val / base, base, val % base, chars...>::result;
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
    static constexpr char const *result = Display<true, val, base, '\0'>::result;
};

int main()
{
    string result(Convert<57005, 8>::result);

    for (char c : result)
    {
        cout << static_cast<int>(c) << "\n";
    }
    
    cout << "<0, 8>: " << Convert<0, 8>::result << "\n";
}