#include "main.ih"

int main(int argc, char **argv)
{
    Process process{
                argc == 1 ? Derived1{ cerr } : Derived2{ cin, cout }
            };
    // etc.
}