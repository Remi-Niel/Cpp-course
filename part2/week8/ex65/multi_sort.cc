#include <thread>
#include <future>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void multi_qsort(int *beg, int *end)
{
    if (end - beg <= 1)
        return;

    int lhs = *beg;
    int *mid = partition(beg + 1, end, 
        [&](int arg)
        {
            return arg < lhs;
        }
    );

    swap(*beg, *(mid - 1));

    auto left_fut = async(launch::async, multi_qsort, beg, mid);
    auto right_fut = async(launch::async, multi_qsort, mid, end);

    //The destructors of the futures will wait for async to finish
}

int main(int argc, char ** argv)
{
    size_t size = stoi(argv[1]);
    int set[size];

    for (size_t idx = 0; idx != size; ++idx)
        set[idx] = rand() % 1000;

    multi_qsort(set, set + size);

    for (size_t idx = 0; idx != size; ++idx)
        cout << set[idx] << ' ';
    cout << '\n';
}
