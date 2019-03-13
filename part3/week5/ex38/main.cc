#include "Scanner.ih"
#include <iostream>
#include <sstream>

using namespace std;

char const *raw = R"foo(te(hlala""st123)foo";

int main()
{

    //test hallo
    stringstream ss; //dumps lexer output
    Scanner scanner(cin, ss);

    int lexxed;
    stringstream store;
    string raw;
    while((lexxed = scanner.lex()) != DONE)
    {
        if (lexxed == STRING_PART)
        {
            store << scanner.matched().substr(1, scanner.matched().size() - 2);
            //should take substr 
        }
        if (lexxed == STRING_DONE)
        {
            cout << "matched:\n";
            cout << store.str() << "\n";
            cout << "---\n";
            store.str("");
        }

        if (lexxed == RAWSTRING)
        {
            cout << "rawstring: "<< scanner.matched() << "\n";
        }
        
    }
    
    string s = "ik test ff een"
            " multiline string!\n";

    cout << "Missed stuff:\n";
    cout << ss.str() << "\n";

}