#include <iostream>

using namespace std;

template <typename Type>
struct RefType
{
    static constexpr int type = 1;
};

template <typename Type>
struct RefType<Type*>
{
    static constexpr int type = 2;
};

template <typename Type>
struct RefType<Type&>
{
    static constexpr int type = 3;
};

template <typename Type>
struct RefType<Type&&>
{
    static constexpr int type = 4;
};

int main()
{
    cout << RefType<int>::type << "\n";
    cout << RefType<int*>::type << "\n";
    cout << RefType<int&>::type << "\n";
    cout << RefType<int&&>::type << "\n";
}
