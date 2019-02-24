#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

template <char ...Chrs>
class Chars
{

    public:
        string operator()()
        {
            return string{Chrs...};
        }
};

template <char Char>
class OneChar
{};

#include "merge.h"

int main()
{
    Merge<Chars<'1','2','3'>,Merge<Chars<'4','5'>,OneChar<'6'>>::CP object;

    cout << object() << '\n';

}





