#include "main.ih"

void prompt(string const &file)
{

    cout << "? ";
    string buffer;
    getline(cin, buffer);

    ofstream out(file.c_str(), ofstream::app);
    out << buffer << "\n";
}