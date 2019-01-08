#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv)
{
    unordered_multimap<string, string> container;
    

    size_t nUniqueKeys = 0;

    //For each unique element that occurs in the set,
    // add 1/n n times to the count. Where n is the
    // amount of times it occurs in the container
    for (pair<string, string> &entry, container)
    	nUniqueKeys += 1 / container.count(entry);

    // size_t nUniqueKeys = count_if
    // (
    //     container.begin(),
    //     container.end(),
    //     bind
    //     (
    //         [](pair<string, string> const &entry, unordered_set<string> &keys)
    //         {
    //             auto result = keys.insert(entry.first);
    //             return result.second;
    //         },
    //         placeholders::_1,
    //         unordered_set<string>()
    //     )
    // );
    
    cout << "There are " << nUniqueKeys << " in the container\n";
}
