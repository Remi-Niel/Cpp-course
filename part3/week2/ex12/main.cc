#include "data.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;


int main()
{

    Data data{};

    copy(istream_iterator<string>(cin),
         istream_iterator<string>(),
         back_inserter(data));

}