#include "main.ih"

int main(int argc, char** argv)
{
    vector<string> words;

    Scanner scanner;

    if (argc == 1)
        readInput(scanner, words);
    else
    {
        for (size_t idx = 1; idx != argc; ++idx)
        {
            scanner.switchIstream(argv[idx]);
            readInput(scanner,words);
        }
    }

    sort(words.begin(), words.end());

    for (size_t idx = 0; idx != words.size(); ++idx)
        cout << words[idx] << '\n';
}