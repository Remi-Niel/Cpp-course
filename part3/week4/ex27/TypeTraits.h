#ifndef TYPETRAITS_
#define TYPETRAITS_

//Checking for string type is not necesarry here
// those are catcher by the function template specialisation
// Data::get<std::string>.
//We distinguish between floating and integral numbers by 
// attempting floating division integral type would give a
// larger number then te correct answer.
template <typename Type>
struct TypeTraits
{
    enum
    {
        isIntegral = Type{3} / static_cast<Type>(1.5) > 2,
        isFloating = Type{3} / static_cast<Type>(1.5) < 3
    };
};

#endif