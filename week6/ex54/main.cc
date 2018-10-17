#include "main.ih"

int main()
{

    string str1("b");
    string str2("d");
    string str3("a");
    string str4("c");
    string** arr1 = new string *[4];
    arr1[0] = &str1;
    arr1[1] = &str2;
    arr1[2] = &str3;
    arr1[3] = &str4;

    for (size_t i = 0; i != 4; ++i)
    {
        cout << *arr1[i] << '\n';
    }

    Sorter sorter = Sorter(Sorter::increasing);
    sorter.sort(arr1, 4);
    
    for (size_t i = 0; i != 4; ++i)
    {
        cout << *arr1[i] << '\n';
    }

    delete[] arr1;
}