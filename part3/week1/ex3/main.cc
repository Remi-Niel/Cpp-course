#include <iostream>
#include <string>

using namespace std;

template <typename T>
T* rawCapacity(size_t size)
{
    return reinterpret_cast<T *>(new char[size * sizeof(T)]);
}