#include "main.ih"

int main(int argc, char **argv)
try
{
    Option::instance().initialize(argc, argv);

    Producer producer{Option::instance().input()};
    producer.run();

}
catch (...)
{
    return 1;
}
