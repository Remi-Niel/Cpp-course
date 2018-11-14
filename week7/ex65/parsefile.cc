#include "main.ih"

void parse_file(string const &filename, bool print_all)
{
    ifstream in(filename);

    if (!in.good())
    {
        cout << "Failed to open file: " << filename << "\n.";
        return;
    }

    while (in)
    {
        acct_v3 data;
        in.read(reinterpret_cast<char *>(&data), sizeof(data));
        
        if (data.ac_exitcode || print_all)
            print_exit(data);
    }

}