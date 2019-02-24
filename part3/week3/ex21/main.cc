#include <cstddef>
#include <iostream>
#include <tuple>
#include <type_traits>

using namespace std;


template<typename Needle, size_t x, typename ...Haystack>
class TypeIdx
{
    tuple<Haystack ...> d_tuple;
    public:
        //Get type of (length-x)'th value from haystack 
        typedef typename tuple_element<sizeof ...(Haystack) - x, decltype(d_tuple)>::type T; 
        //If the type is the same as Needle set located to N - x + 1 with N being length of haystack,
        // otherwise check next location.
        enum {located = is_same<Needle, T>::value ? sizeof ...(Haystack) - x + 1 :
                TypeIdx<Needle, x-1, Haystack ...>::located};
};

//If haystack empty, needle is not encountered hence located = 0
template<typename Needle, typename ...Haystack>
class TypeIdx<Needle, 0, Haystack...>
{
    public:
        enum {located = 0};
};

template<typename Needle, typename ...Haystack>
class Type
{
    public:
        //Start search for needle at the first location.
        enum {located = TypeIdx<Needle, sizeof ...(Haystack), Haystack ...>::located};
};

int main()
{
    cout <<
        Type<int>::located << ' ' <<
        Type<int, double>::located << ' ' <<
        Type<int, int>::located << ' ' <<
        Type<int, double, int>::located << ' ' <<
        Type<int, double, int>::located << ' ' <<
        Type<int, double, int, int, int>::located << ' ' <<
        '\n';
}