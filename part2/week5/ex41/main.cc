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
    
    // fill the container with data (no need to implement this)

    // this is probably not the requested answer, but it's something...
    size_t nUniqueKeys = count_if
    (
        container.begin(),
        container.end(),
        bind
        (
            [](pair<string, string> const &entry, unordered_set<string> &keys)
            {
                auto result = keys.insert(entry.first);
                return result.second;
            },
            placeholders::_1,
            unordered_set<string>()
        )
    );
    
    cout << "There are " << nUniqueKeys << " in the container\n";
}