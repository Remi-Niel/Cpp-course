#include "main.ih"

void gSort(auto begin, auto end, auto less)
{
    if (begin >= end)
        return;
    
    /* Wraps begin, and the less function into the UnaryPredicate */
    auto mid = partition(begin, end, 
        [&](auto const &val)
        {
            return less(val, *begin);
        }
    );
    
    // recursive qsort.
    gSort(begin, mid, less);
    gSort(mid + (begin == mid), end, less);
}

/*
    Delegates to actual sorting function with a default less function.
*/
void gSort(auto begin, auto end)
{
    gSort(begin, end, 
        [](auto const &v1, auto const &v2)
        {
            return v1 < v2;
        }
    );
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