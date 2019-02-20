#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include "forwarder.h"

using namespace std;

void fun(int first, int second)
{
    cout << "int fun(" << first << ", " << second << ")\n";
}

void fun(double &&first, double &&second)
{
    cout << "double && fun(" << first << ", " << second << ")\n";
}

void fun2(int &&first, int &&second)
{
    cout << "int && fun(" << first << ", " << second << ")\n";
}
                                        // increments each argument:
void incrementer(int &one, int &two, int &three)
{
    ++one;
    ++two;
    ++three;
}

int main()
{
    forwarder<void (*)(int, int), int>(fun, 1, 3);       // should show 'fun(1, 3)' to cout
    forwarder<void (*)(double &&, double &&), double &&>(fun, double{}, double{});
                                // fun2 expects two rvalue references 
    forwarder(fun2, int{}, int{});

    forwarder(plus<string>(), "hello ", "world");


    vector<int> first;
    forwarder(                  // receives a lambda function
        [](vector<int> &first, vector<int> const &second, 
                                vector<int> const &third)
        {
            // modify first's elements using second's and third's
            // elements
        }, first, vector<int>{}, vector<int>{}
    );

    int x = 0;
    forwarder(incrementer, x, x, x);
    cout << x << '\n';          // should show '3'
}
    