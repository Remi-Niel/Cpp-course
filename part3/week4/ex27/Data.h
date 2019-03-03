#ifndef DATA_
#define DATA_

#include <vector>
#include <string>

class Data
{
    std::vector<std::string> d_data = {"test", "2.2", "test", "2"};

    public:
        template<typename Type>
        auto get(size_t idx) const;

};


//Catches specific case in which the type is string
template<>
auto Data::get<std::string>(size_t idx) const
{
    return std::as_const(d_data[idx]);
}

//Convert to integral or floating number depending on type,
// and cast it to Type
template<typename Type>
auto Data::get(size_t idx) const
{
    try
    {
        if (TypeTraits<Type>::isIntegral)
            return static_cast<Type>(std::stoll(d_data[idx].data()));
        else
            return static_cast<Type>(std::stold(d_data[idx].data()));
    }
    catch(const std::invalid_argument& e)
    {
        return Type{};
    }
    
}

#endif