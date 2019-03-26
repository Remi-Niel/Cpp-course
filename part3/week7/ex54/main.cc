#include "main.ih"

int main(int argc, char **argv)
{
    Parser parser;
    int temp = parser.parse();
    
    cout << temp << '\n';
    
    return temp == 0 ? 0 : 1;
}
