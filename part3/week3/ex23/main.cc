#include <cstddef>
#include <iostream>
#include <type_traits>

using namespace std;

template<typename Needle, typename ...Haystack>
class Type
{
    template<typename First, typename ...ReducedStack>
    class TypeIdx;

    public:
        //Start search for needle at the first location.
        enum {located = TypeIdx<Haystack...>::located};

    template<typename First, typename ...ReducedStack>
    friend class TypeIdx;
};
 
//Catch the edge case where Haystack is empty
//Clearly Needle will not be encountered hence located = 0
template<typename Needle>
class Type<Needle>
{
    public:
        enum {located = 0};
};

template<typename Needle, typename ...Haystack>
template<typename First, typename ...ReducedStack>
class Type<Needle, Haystack...>::TypeIdx
{
    public:
        // If Needle and first are the same return 1, 
        // otherwise add 1 to the result of the next recursion.
        enum
        {
            located = is_same<Needle, First>::value 
                ?  1 
                : Type<Needle, Haystack...>
                    ::TypeIdx<ReducedStack...>::located + 1
        };
};

//When the reduced stack is empty
template<typename Needle, typename ...Haystack>
template<typename First>
class Type<Needle, Haystack...>::TypeIdx<First>
{
    public:
        enum
        {
            // If the final member of the haystack == needle return 1 
            // otherwise return the negated index of the last element. 
            // This way the additions by the other levels in the 
            // recursion get cancelled out to 0.
            located = is_same<Needle, First>::value 
                ? 1
                : - (sizeof ...(Haystack) - 1)
        };
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