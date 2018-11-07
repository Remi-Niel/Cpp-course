#include "main.ih"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << "program expects 1 argument, a filename which to write to\n";
        return -1;
    }

    Lock lock(argv[1]);
    prompt(argv[1]);
}