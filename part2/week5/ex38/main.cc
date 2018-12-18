#include "main.ih"

int main(int argc, char **argv)
{
    Strings test;

    test += string("test");

    Strings test1{test};
    Strings test3;
    test3 = test;

    cout << test[0] << '\n';
    cout << test1[0] << '\n';
    cout << test3[0] << '\n';
}
