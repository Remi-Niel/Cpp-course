#include <cstddef>
#include <iostream>
#include <tuple>
#include <type_traits>

using namespace std;

template<size_t val,char... chars>
struct I2C_Helper{
<<<<<<< HEAD
    // add the last number of val to the front of the parameter pack,
    // and recursively call I2C_Helper::res with val = val/10
    static constexpr char const* res= I2C_Helper<val/10, '0' + val % 10, chars...>::res;
=======
    static constexpr char const* res =
        I2C_Helper<val/10, '0' + val % 10, chars...>::res;
>>>>>>> 90d8ce7b18557039cc30bd6f0306e2c63eeec8eb
};

// when val == 0 nothing left over, so create character array from parameter pack
template<char... chars>
struct I2C_Helper<0,chars...>{
    static constexpr char const res[sizeof ...(chars)]= {chars...};
};

//Starting step needed to catch val = 0, otherwise it would
// return empty array in that case.
template<size_t val, char... chars>
struct I2C_Step{
    static constexpr char const* res =
        I2C_Helper<val/10, '0' + val % 10, chars...>::res;
};

template<size_t val>
struct I2C{
    static constexpr char const *s_ch = I2C_Step<val,'\0'>::res;
    static constexpr char const *s_ntbs = I2C_Step<val,'\0'>::res;
};

int main()
{
    cout << I2C<123>::s_ch << '\n';
    cout << I2C<0>::s_ntbs << '\n';

    string value{I2C<15937>::s_ntbs};
    cout << value << '\n';
    
}