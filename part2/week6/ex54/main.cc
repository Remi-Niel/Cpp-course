#include "main.ih"

/*
    Copiled with the following command:
        g++ -std=c++17 -Wall -Wpedantic -fconcepts main.cc

    With gcc version 8.2.1

*/

void gSort(auto begin, auto end, auto binaryPred)
{
    if (begin >= end)
        return;
    
    /* Wraps begin, and the binary predicate function into the UnaryPredicate */
    auto mid = partition(begin, end, 
        [&](auto const &val)
        {
            return binaryPred(val, *begin);
        }
    );
    
    // recursive qsort.
    gSort(begin, mid, binaryPred);
    gSort(mid + (begin == mid), end, binaryPred);
}

/*
    Delegates to actual sorting function with a default less function.
*/
void gSort(auto begin, auto end)
{
    //less<void> deduces parameter and return types.
    gSort(begin, end,less<>{});
}

// typedef string Type;
typedef int Type;

int main()
{
    // vector<Type> vs = get_random_strings();
    vector<Type> vs = get_random_ints();

    cout << "initial:\n";
    for (auto const &val : vs)
    {
        cout << val << "\n";
    }
    cout << "\n";

    // both work
    // gSort(vs.begin(), vs.end());
    gSort(vs.begin(), vs.end(), less<Type>());

    cout << "result:\n";
    for (auto const &val : vs)
    {
        cout << val << "\n";
    }
}
