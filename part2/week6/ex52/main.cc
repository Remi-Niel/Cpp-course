#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{   
    // construct stream reading the first file
    ifstream in{argv[1]};
    // read contents into vector data
    vector<string> data
    {
        istream_iterator<string>(in),
        istream_iterator<string>()
    };

    // close stream, clear flags and reopen it for file 2
    in.close();
    in.clear();
    in.open(argv[2]);

    // read contents into vector data2
    vector<string> data2
    {
        istream_iterator<string>(in),
        istream_iterator<string>()
    };

    // delete the word 'extra' from data
    // remove_if moves all 'to remove' items to the back of the vector, and
    // returns the iterator to the first to-be removed item.
    // erase then actually deletes values in a range, in this case between
    // remove_if's return value and the end.
    data.erase(remove_if(data.begin(), data.end(),
        [](string const &str)
        {
            return str == "extra";
        }), 
        data.end());

    // append data2 after data.
    data.insert(data.end(), data2.begin(), data2.end());

    // insert all words into a set, effectively removing all doubles
    set<string> uniques{data.begin(), data.end()};

    // overwrite data with a new vector constructed from the set's contents.
    data = vector<string>{uniques.begin(), uniques.end()};
    cout << "size/cap: " << data.size() << " / " << data.capacity() << "\n";

    for (string const &str : data)
        cout << str << "\n";
}