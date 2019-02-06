#include "compilation.ih"

void report_errors(string const &path)
{
    ifstream file{path};

    if(file.good())
        cout << file.rdbuf();
    else
        cout << "Error printing errors xD\n";
}