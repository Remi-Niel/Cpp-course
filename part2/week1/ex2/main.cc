#include <iostream>
#include <string>

using namespace std;

bool promptGet(istream &in, string &str)
{
    cout << "Enter a line or ^D\n";     // ^D signals end-of-input

    return static_cast<bool>(getline(in, str));
}

int main()
{
    string buffer;

    while(promptGet(cin, buffer))
        cout << buffer;

}