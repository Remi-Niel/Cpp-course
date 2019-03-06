#include <cstddef>
#include <iostream>

using namespace std;

template<size_t val,char... chars>
struct I2C_Helper{
    static constexpr char const* res =
        I2C_Helper<val/10, '0' + val % 10, chars...>::res;
};

// when val == 0 nothing left over, so create character array from parameter pack
template<char... chars>
struct I2C_Helper<0,chars...>{
    static constexpr char const res[] = {chars...};
};

//Starting step needed to catch val = 0, otherwise it would
// return empty array in that case.
template<size_t val, char... chars>
constexpr char const *I2C_Step(){
    return I2C_Helper<val/10, '0' + val % 10, chars...>::res;
};

template<size_t val>
struct I2C{
    static constexpr char const *s_ch = I2C_Step<val,'\0'>();
    static constexpr char const *s_ntbs = I2C_Step<val,'\0'>();
};

int main()
{
    cout << I2C<123>::s_ch << '\n';
    cout << I2C<0>::s_ntbs << '\n';

    string value{I2C<15937>::s_ntbs};
    cout << value << '\n';
    
}