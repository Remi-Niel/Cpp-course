#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include "Scanner.h"

using namespace std;

int main()
{
    Scanner scanner;
    deque<string> stack;

    string filename;
    bool done = false;
    while(!done)
    {
        switch (scanner.lex())
        {
            case INCLUDE:
                filename  = scanner.matched().substr(0, scanner.matched().size() - 1);
                if (find(stack.begin(), stack.end(), filename) == stack.end())
                {
                    scanner.pubPushStream(filename);
                    stack.push_back(filename);
                }
                else
                {
                    cerr << "\n\nnested includes of the same file not allowed\n";
                    return 1;
                }
                break;
            case END:
                if(stack.size() != 0)
                {
                    stack.pop_back();
                    scanner.pubPopStream();
                }
                else
                    done = true;
                break;
            default:
                cerr << "Something went wrong: " << scanner.matched() << '\n'; 
        }
    }
}