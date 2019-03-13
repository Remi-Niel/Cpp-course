#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
    const char alpha[] = "badcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXZY";
    vector<string> dictionary;

    istream *input = &cin;    

    string line;
    size_t right, left;

    //If argc is 1 loop should execute once for cin
    //Else loop should start at 1
    size_t idx = argc == 1 ? 0 : 1; 

    for (; idx != argc; ++idx)
    {
        if (argc > 1)
            input = new ifstream(argv[idx]);
        
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
        if (argc > 1)
            delete dynamic_cast<ifstream*>(input);
    }
    
    sort(dictionary.begin(), dictionary.end());

    for (auto iter = dictionary.begin(); iter != dictionary.end(); ++iter)
        cout << *iter << '\n';
}