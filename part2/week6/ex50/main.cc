#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

class Line : public string
{ };

istream &operator>>(istream &in, Line &line)
{
    getline(in, line);
    return in;
}

int main()
{
    vector<string> vs
    {
        istream_iterator<Line>(cin),
        istream_iterator<Line>()
    };

    for (string const &str : vs)
        cout << str << "\n";
}