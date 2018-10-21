#include "main.ih"

int main(int argc, char **argv)
{
    cout.setstate(ios::failbit);

    for (size_t idx = 0; idx != stoul(argv[1]); ++idx)
        cout << "Nr. of command line arguments " << argc << '\n';
}