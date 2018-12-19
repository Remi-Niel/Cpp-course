#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    unordered_multimap<string, string> container;
    
    // fill the container with data (no need to implement this)

    size_t nUniqueKeys = container.bucket_count();
    
    cout << "There are " << nUniqueKeys << " in the container\n";
}