#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void print_args(int argc, char *argv[])
{
    for (size_t idx = 0; idx < static_cast<size_t>(argc); ++idx)
        cout << argv[idx] << "\n";
}

int main(int argc, char *argv[])
{
    sort(argv, argv + argc, 
        [](string const &left, string const &right)
        {
            return left < right;
        });

    cout << "Ascending:\n";
    print_args(argc, argv);

    sort(argv, argv + argc, 
        [](string const &left, string const &right)
        {
            return left > right;
        });

    cout << "Descending:\n";
    print_args(argc, argv);
}
