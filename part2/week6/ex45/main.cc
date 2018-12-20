#include <iostream>
#include <iterator>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    set<string> word_set;
    
    copy(istream_iterator<string>(cin), istream_iterator<string>(),
            inserter(word_set, word_set.begin()));

    copy(word_set.begin(), word_set.end(), 
            ostream_iterator<string>(cout, "\n"));
}