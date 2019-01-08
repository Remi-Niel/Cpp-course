#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

istream &operator>>(istream &in, string &line)
{
    getline(in, line);
    return in;
}

int main()
{
    vector<string> vs;
}