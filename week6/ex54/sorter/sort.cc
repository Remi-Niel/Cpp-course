#include "sorter.ih"

void Sorter::sort(string **strArrays, size_t arrSize)
{
    cout << "qsort:\n";
    qsort
    (
        strArrays,
        arrSize,
        sizeof(string *),
        reinterpret_cast<int (*)(const void *, const void *)>(cmpFunc)
    );
}