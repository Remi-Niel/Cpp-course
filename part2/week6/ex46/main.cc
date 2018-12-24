#include <random>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    size_t num_vals = atoi(argv[1]);
    size_t max_val  = atoi(argv[2]) + 1;
    size_t lookup   = atoi(argv[3]);

    mt19937 mt_rand(time(0));
    vector<size_t> numbers(num_vals);

    generate_n(numbers.begin(), num_vals, 
        [&]()
        {
            return mt_rand() % max_val;
        }
    );

    copy(numbers.begin(), numbers.end(), ostream_iterator<size_t>(cout, " "));

    auto index = find_if(numbers.begin(), numbers.end(),
        [=](size_t element)
        {
            return (element > lookup);
        }
    );

    if (index != numbers.end())
        cout << "\nThe first value exceeding " << lookup <<
        " is at index " << (index - numbers.begin()) << '\n';
    
    else
        cout << "\nNo random value exceeds " << lookup << '\n';
}