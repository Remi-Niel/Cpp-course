#include "sort.ih"
#include <stdlib.h>

void Sort::sort(string **strArrays, size_t arrSize)
{
    for (size_t ind = 0; ind != arrSize; ++ind)
    {
        cout << "qsort:\n";
        qsort
        (
            strArrays[ind],
            sizeof(strArrays[ind]),
            sizeof(strArrays[ind][0]),
            reinterpret_cast<int (*)(const void *, const void *)>(cmpFunc)
        );
    }
}