#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    const char alpha[] = "badcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXZY";
    vector<string> dictionary;

    ifstream inputFromFile(argv[1]);
    istream *input = &inputFromFile;
    if (argc == 1)
        input = &cin;    


    string line;
    size_t right, left;
    while (getline(*input, line))
    {
        left = 0;
        while (true)
        {
            left = line.find_first_of(alpha, left);
            if (left != string::npos)
            {
                right = line.find_first_not_of(alpha, left);
                dictionary.push_back(line.substr(left, right - left));
                left = right;
            }
            else
                break;
            
            left = right;
        }
    }

    sort(dictionary.begin(), dictionary.end());

    for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
        cout << *iter << '\n';

}