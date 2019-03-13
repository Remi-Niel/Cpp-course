#include "Scanner.ih"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{

    //test hallo
    stringstream ss; //dumps lexer output
    Scanner scanner(cin, ss);

    int lexxed;
    stringstream store;
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
        
    }
    
    string s = "ik test ff een"
            " multiline string!\n";

    cout << "Missed stuff:\n";
    cout << ss.str() << "\n";

}