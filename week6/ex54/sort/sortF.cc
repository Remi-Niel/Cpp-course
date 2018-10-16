#include "sort.ih"
#include <stdlib.h>

void Sort::sort(string **strArrays, size_t arrSize)
{
    for (size_t ind = 0; ind != arrSize; ++ind)
    {
        cout << "ok let op we gaan qsorten\n";
        qsort
        (
            strArrays[ind],
            sizeof(strArrays[ind]) / sizeof(string),
            sizeof(string),
            reinterpret_cast<int (*)(const void *, const void *)>(cmpFunc)
        );
    }
}