#include "main.ih"

int main(int argc, char **argv)
try
{

    Producer producer{argv[1]};
    producer.run();

}
catch (...)
{
    return 1;
}
