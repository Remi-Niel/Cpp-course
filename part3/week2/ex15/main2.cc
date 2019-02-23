#include "main.ih"

int main(int argc, char **argv)
{
    Process process{
                argc == 1 ? 
                    move(ABC::make<Derived1>(cerr)) 
                : 
                    move(ABC::make<Derived2>(cin, cout))
            };
    process.execute();
    // etc.
}