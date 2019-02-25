#include <cstddef>
#include <iostream>
#include <tuple>
#include <type_traits>

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
template<size_t input, bool first>
struct Width
{
    enum {
        value = Width_helper<input / 10>::value + 1
    };
};

//remove last number, add it to the chars
template<size_t val, size_t width, char... chars>
struct I2C_Helper{
    static constexpr char const* res= I2C_Helper<val/10, width - 1, '0' + val % 10, chars...>::res;
};

template<size_t val, char... chars>
struct I2C_Helper<val,0,chars...>{
    static constexpr char const res[sizeof ...(chars)]= {chars...};
};

template<size_t val>
struct I2C{
    static constexpr char const *s_ch = I2C_Helper<val, Width<val,true>::value, '\0'>::res;
    static constexpr char const *s_ntbs = I2C_Helper<val, Width<val,true>::value,'\0'>::res;
};

int main()
{
    cout << I2C<123>::s_ch << '\n';
    cout << I2C<0>::s_ntbs << '\n';

    string value{I2C<15937>::s_ntbs};
    cout << value << '\n';
    
}