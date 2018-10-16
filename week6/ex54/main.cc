#include <iostream>
#include "sort/sort.h"

int main()
{
    string* arr1 = new string[10];
    arr1[0] = "hi there!";
    arr1[1] = "ello";
    arr1[2] = "buenos dias";
    arr1[3] = "allo";

    for (size_t i = 0; i != 10; ++i)
    {
        cout << arr1[i] << '\n';
    }

    Sort* sorter = new Sort(Sort::increasing);
    sorter->sort(&arr1, 1);
    
    for (size_t i = 0; i != 10; ++i)
    {
        cout << arr1[i] << '\n';
    }
}