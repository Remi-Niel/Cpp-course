#include "main.ih"

int main(int argc, char **argv)
{
    Process process{
                argc == 1 ? static_cast<ABC&&>((Derived1{ cerr })) : static_cast<ABC&&>(Derived2{ cin, cout })
            };
            
    process.execute();
    // etc.
}