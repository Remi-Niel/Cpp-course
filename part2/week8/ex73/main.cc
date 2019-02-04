#include "main.ih"

int main(int argc, char **argv)
try
{

    Worker worker{1000};
    worker.run();

}
catch (...)
{
    return 1;
}
