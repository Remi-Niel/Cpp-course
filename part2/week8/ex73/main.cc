#include "main.ih"

int main(int argc, char **argv)
try
{
    BigInt max {3000000};
    
    Worker worker{max};
    worker.run();

}
catch (...)
{
    return 1;
}
