#include <iostream>
#include "sort/sort.h"

int main()
{
    string* arr1 = new string[20];
    arr1[0] = "hi there!";
    arr1[1] = "ello guvnor";
    arr1[2] = "buenos dias hijos de puta";

    for (int i = 0; i != 20; ++i)
    {
        cout << arr1[i] << '\n';
    }

    Sort* sorter = new Sort(Sort::increasing);
    sorter->sort(&arr1, 1);
    
    for (int i = 0; i != 20; ++i)
    {
        cout << arr1[i] << '\n';
    }
}