#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include "TypeTraits.h"
#include "Data.h"

int main()
{
    Data data;
    std::cout << TypeTraits<int>::isIntegral << '\n';
    std::cout << TypeTraits<float>::isIntegral << "\n\n";
    
    std::cout << data.get<int>(3) << '\n';
    std::cout << data.get<long double>(1) << '\n';
    std::cout << data.get<std::string>(2) << '\n';
}