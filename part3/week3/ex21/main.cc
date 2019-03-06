#include <cstddef>
#include <iostream>
#include <type_traits>

using namespace std;

//Default case Needle != Test so recursive call with the rest of haystack
template<typename Needle, typename Test, typename ...Haystack>
class TypeIdx
{
    public:
        enum 
        {
            located = TypeIdx<Needle, Haystack ...>::located + 1
        };
};

//Success Needle == Test so located = 1;
template<typename Needle, typename ...Haystack>
class TypeIdx<Needle, Needle, Haystack...>
{
    public:
        enum 
        {
            located = 1
        };
};

//Final element of haystack is not of the same type
// located = 0
template<typename Needle, typename Test>
class TypeIdx<Needle, Test>
{
    public:
        enum 
        {
            located = 0
        };
};

//Success with empty remaining haystack,
// added to avoid ambiguity.
template<typename Needle>
class TypeIdx<Needle, Needle>
{
    public:
        enum 
        {
            located = 1
        };
};

template<typename Needle, typename ...Haystack>
class Type
{
    public:
        //Start search for needle at the first location.
        enum 
        {
            located =
                TypeIdx<Needle, Haystack ...>::located
        };
};

template<typename Needle>
class Type<Needle>
{
    public:
        enum 
        {
            located = 0
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